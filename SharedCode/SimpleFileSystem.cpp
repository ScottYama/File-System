/*SimpleFileSystem.cpp: This file contains the class definitions for SimpleFileSystem.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "SimpleFileSystem.h"
#include <iostream>

using namespace std;
//This function adds a file to the file system
int SimpleFileSystem::addFile(string name, AbstractFile* af) {
    //Check if the file name already exists
    map<string, AbstractFile*>::iterator it = m.begin();
    while (it != m.end()) {
        if (it->first == name) {
            return 3;
        }
        ++it;
    }
    //Check if the Abstract File Pointer is a null pointer
    if (af == nullptr) {
        return 4;
    }
    //Add the pair to the map of files
    pair<string, AbstractFile*> p(name, af);
    m.insert(p);
    return 0;
}

//This method opens the file from the file system so that we can use it.
AbstractFile* SimpleFileSystem::openFile(string name) {
    map<string, AbstractFile*>::iterator it = m.begin();
    set<AbstractFile*>::iterator it2 = s.begin();
    //Add the file to the set of files that are open
    while (it != m.end()) {
        if (it->first == name) {
            while (it2 != s.end()) {
                if (*it2 == it->second) {
                    return nullptr;
                }
                ++it2;
            }
            s.insert(it->second);
            return it->second;
        }
        ++it;
    }
    return nullptr;
}

//This method closes the file by removing it from the set of opened files.
int SimpleFileSystem::closeFile(AbstractFile* ab) {
    set<AbstractFile*>::iterator it3 = s.begin();
    while (it3 != s.end()) {
        if (*it3 == ab) {
            s.erase(*it3);
            return 0;
        }
        ++it3;
    }
    return 6;
}
//This method deletes the file from the file system
int SimpleFileSystem::deleteFile(string name) {
    map<string, AbstractFile*>::iterator it4 = m.begin();
    set<AbstractFile*>::iterator it5 = s.begin();
    AbstractFile* fileP;
    while (it4 != m.end()) {
        if (it4->first == name) {
            //Check if the file is open
            while (it5 != s.end()) {
                if (*it5 == it4->second) {
                    return 7;
                }
                ++it5;
            }
            //delete the file
            fileP = it4->second;
            m.erase(it4);       
            delete fileP;
            return 0;
        }
        ++it4;
    }
    return 8;
}
//This file returns a set with the names of all the files in the file system.
set<string> SimpleFileSystem::getFileNames() {
    auto iterator = m.begin();
    set<string> names;
    while (iterator != m.end()) {
        names.insert(iterator->first);
        ++iterator;
    }
    return names;
}