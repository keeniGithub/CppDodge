#ifndef DISK
#define DISK

#include <iostream>   
#include <direct.h>

using namespace std;

char disk_path() {
    const size_t size = 1024; 
    char buffer[size];

    getcwd(buffer, size);

    string path = string(buffer);

    return buffer[0];
}

#endif