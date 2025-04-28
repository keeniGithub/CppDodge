#ifndef SAVE
#define SAVE

#include <fstream>

using namespace std;

void save(int count) {
    ofstream saveFile("save.txt");
    if (saveFile.is_open()) {
        saveFile<<count<<endl;
        saveFile.close();
    }
}

void load(int &count) {
    ifstream saveFile("save.txt");
    if (saveFile.is_open()) {
        saveFile>>count;
        saveFile.close();
    }
}

#endif