//
// Created by zxilly on 2021/9/30.
//

#include<windows.h>
#include<tlhelp32.h>
#include<iostream>

using namespace std;

DWORD GetKernelModePercentage(const FILETIME &ftKernel, const FILETIME &ftUser) {
    ULONGLONG qwKernel = (((ULONGLONG) ftKernel.dwHighDateTime) << 32) + ftKernel.dwLowDateTime;
    ULONGLONG qwUser = (((ULONGLONG) ftUser.dwHighDateTime) << 32) + ftUser.dwLowDateTime;
    ULONGLONG qwTotal = qwKernel + qwUser;
    auto dwPct = (DWORD) (((ULONGLONG) 100 * qwKernel) / qwTotal);
    return (dwPct);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Use process you want to check." << endl;
        exit(0);
    }
    HANDLE hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    PROCESSENTRY32 pe;
    ::ZeroMemory(&pe, sizeof(pe));
    pe.dwSize = sizeof(pe);
    BOOL bMore = ::Process32First(hSnapshot, &pe);
    BOOL found = FALSE;
    while (bMore) {
        if (!strcmp(pe.szExeFile, argv[1])) {
            found = TRUE;
            HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pe.th32ProcessID);
            if (hProcess != nullptr) {
                FILETIME ftCreation, ftKernelMode, ftUserMode, ftExit;
                ::GetProcessTimes(
                        hProcess,
                        &ftCreation,
                        &ftExit,
                        &ftKernelMode,
                        &ftUserMode
                );
                DWORD dwPctKernel = ::GetKernelModePercentage(ftKernelMode, ftUserMode);
                cout << "Process ID:" << pe.th32ProcessID << endl
                     << "EXE file:" << pe.szExeFile << endl
                     << "Running in Kernel mode time percent:" << dwPctKernel << endl;

                ::CloseHandle(hProcess);
            }
        }
        bMore = ::Process32Next(hSnapshot, &pe);
    }
    if (found == FALSE) {
        cout << "Process not found." << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}