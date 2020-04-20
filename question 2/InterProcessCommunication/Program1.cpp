#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>

#define BUF_SIZE sizeof(data)
TCHAR szName[] = TEXT("Global\MyFileMappingObject");


struct data {
    bool program1Trurn = true;
    size_t noWords = 0;
    size_t noLetters = 0;
    size_t noDigits = 0;
}_globalData;

bool isAlpha(char c) {
    if (c >= '0' && c <= '9')return true;
    if (c >= 'a' && c <= 'z')return true;
    if (c >= 'A' && c <= 'Z')return true;
    return false;
}

int main()
{
    HANDLE hMapFile;
    data* pBuf;

    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // use paging file
        NULL,                    // default security
        PAGE_READWRITE,          // read/write access
        0,                       // maximum object size (high-order DWORD)
        BUF_SIZE,                // maximum object size (low-order DWORD)
        szName);                 // name of mapping object

    if (hMapFile == NULL)
    {
        std::cout << "Could not create file mapping object " << GetLastError() << " ." << std::endl;

        system("pause");
        return 1;
    }
    pBuf = (data*)MapViewOfFile(hMapFile,   // handle to map object
        FILE_MAP_ALL_ACCESS, // read/write permission
        0,
        0,
        BUF_SIZE);

    if (pBuf == NULL)
    {
        std::cout << "Could not map view of file " << GetLastError() << " ." << std::endl;
        CloseHandle(hMapFile);

        system("pause");
        return 1;
    }
    CopyMemory(pBuf, &_globalData, BUF_SIZE);

    const unsigned int msgSize = 256;
    char msg[msgSize];
    while (1){
        if (pBuf->program1Trurn) {
            std::cout << "ener the string : ";
            std::cin.getline(msg, msgSize);
            //reset global Data
            _globalData.program1Trurn = false;
            _globalData.noDigits = 0;
            _globalData.noLetters = 0;
            _globalData.noWords = 0;
            //calculate no of digits , letters
            for (unsigned int i = 0; i < msgSize && msg[i] != '\0'; ++i) {
                if (msg[i] >= '0' && msg[i] <= '9')_globalData.noDigits++;
                if (msg[i] >= 'a' && msg[i] <= 'z')_globalData.noLetters++;
                if (msg[i] >= 'A' && msg[i] <= 'Z')_globalData.noLetters++;
            }

            //no of words
            if (msg[0] != '\0') {
                if (isAlpha(msg[0]))_globalData.noWords++;
                for (unsigned int i = 1; i < msgSize && msg[i] != '\0'; ++i) {
                    if (isAlpha(msg[i]) && (!isAlpha(msg[i - 1])))_globalData.noWords++;
                }
            }
            
            CopyMemory(pBuf, &_globalData, BUF_SIZE);
        }
    }

    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}