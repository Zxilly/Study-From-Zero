#include <windows.h>
#include <iostream>

using namespace std;
const int SIZE_OF_BUFFER = 10;
int ProductID = 0;         
int ConsumeID = 0;         
int in = 0;             
int out = 0;             

int g_buffer[SIZE_OF_BUFFER];         
bool g_continue = true;
HANDLE g_hMutex;               
HANDLE g_hFullSemaphore;           
HANDLE g_hEmptySemaphore;

void Clear()
{

}

void Produce() {
    cout << "Produce new:" << ++ProductID << endl;
    g_buffer[in] = ProductID;
    in = (in + 1) % SIZE_OF_BUFFER;
    for (int i = 0; i < SIZE_OF_BUFFER; ++i) {
        cout << i << ":   " << g_buffer[i];
        if (i == in) cout << "   <--   Produce";
        if (i == out) cout << "   <--   Consume";
        cout << endl;
    }
    cout << endl;
}


void Consume() {
    cout << "Consume new:" << g_buffer[out] << endl;
    g_buffer[out] = 0;
    out = (out + 1) % SIZE_OF_BUFFER;

    
    for (int i = 0; i < SIZE_OF_BUFFER; ++i) {
        cout << i << ":   " << g_buffer[i];
        if (i == in) cout << "   <--   Produce";
        if (i == out) cout << "   <--   Consume";
        cout << endl;
    }
    cout << endl;
}


DWORD WINAPI Producer(LPVOID lpPara) {
    while (g_continue) {
        WaitForSingleObject(g_hEmptySemaphore, INFINITE);    
        WaitForSingleObject(g_hMutex, INFINITE);             
        Produce();
        Sleep(1000);
        ReleaseMutex(g_hMutex);
        ReleaseSemaphore(g_hFullSemaphore, 1, nullptr);
    }
    return 0;
}


DWORD WINAPI Consumer(LPVOID lpPara) {

    while (g_continue) {
        WaitForSingleObject(g_hFullSemaphore, INFINITE);
        WaitForSingleObject(g_hMutex, INFINITE);
        Consume();
        Sleep(2000);
        ReleaseMutex(g_hMutex);
        ReleaseSemaphore(g_hEmptySemaphore, 1, nullptr);
    }
    return 0;
}


int main() {
    g_hMutex = CreateMutex(nullptr, FALSE, nullptr);
    g_hFullSemaphore = CreateSemaphore(nullptr, 0, SIZE_OF_BUFFER, nullptr);
    g_hEmptySemaphore = CreateSemaphore(nullptr, SIZE_OF_BUFFER, SIZE_OF_BUFFER, nullptr);

    const int PRODUCERS_COUNT = 6;     
    const int CONSUMERS_COUNT = 2;     

    const int THREADS_COUNT = PRODUCERS_COUNT + CONSUMERS_COUNT;

    HANDLE hThreads[THREADS_COUNT];   
    DWORD producerID[PRODUCERS_COUNT];   
    DWORD consumerID[CONSUMERS_COUNT];   

    
    for (int i = 0; i < PRODUCERS_COUNT; ++i) {
        hThreads[i] = CreateThread(nullptr, 0, Producer, nullptr, 0, &producerID[i]);
        if (hThreads[i] == nullptr) return -1;
    }
    
    for (int j = 0; j < CONSUMERS_COUNT; ++j) {
        hThreads[PRODUCERS_COUNT + j] = CreateThread(nullptr, 0, Consumer, nullptr, 0, &consumerID[j]);
        if (hThreads[j] == nullptr) return -1;
    }

    while (g_continue) {
        if (getchar()) {
            g_continue = false;
        }
    }
    return 0;
}