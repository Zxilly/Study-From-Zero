//
// Created by zxilly on 2021/8/22.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile;
    outFile.open("Test.tmp");

    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Test";
    outFile.close();
    return 0;
}