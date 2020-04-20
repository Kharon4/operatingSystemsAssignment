#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE sizeof(data)
TCHAR szName[] = TEXT("Global\MyFileMappingObject");

struct data {
    bool program1Trurn = true;
    size_t noWords = 0;
    size_t noLetters = 0;
    size_t noDigits = 0;
}_globalData;

int main()
{
    HANDLE hMapFile = NULL;
    data* pBuf;

    std::cout << "trying to find shared memory mapping object : .." ;


    while (hMapFile == NULL){
        std::cout << ".";
        hMapFile = OpenFileMapping(
                FILE_MAP_ALL_ACCESS,   // read/write access
                FALSE,                 // do not inherit the name
                szName);               // name of mapping object
        
    }

    std::cout << std::endl << "Shared memory block (mapping object) found" << std::endl << std::endl;


    pBuf = (data*)MapViewOfFile(hMapFile, // handle to map object
        FILE_MAP_ALL_ACCESS,  // read/write permission
        0,
        0,
        BUF_SIZE);

    if (pBuf == NULL)
    {
        std::cout << "Could not map view of file " << GetLastError() << " ." << std::endl;
        system("pause");
        CloseHandle(hMapFile);

        return 1;
    }

    _globalData.program1Trurn = true;
    while (1) {
        if (!pBuf->program1Trurn) {
            std::cout << "no of digits = " << pBuf->noDigits << " , no of letters = "<<pBuf->noLetters<<" , no of words = "<<pBuf->noWords<<std::endl;
            CopyMemory(pBuf, &_globalData, BUF_SIZE);
        }
    }
    UnmapViewOfFile(pBuf);

    CloseHandle(hMapFile);

    return 0;
}