#ifndef DISK
#define DISK

#include <iostream>   
#include <direct.h>

using namespace std;

string disk_path() {
    const size_t size = 1024; 
    char buffer[size];

    char* pathname = getcwd(buffer, 1024);

    return pathname;
}

#endif