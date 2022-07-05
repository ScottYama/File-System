/* SimpleFileFactory.cpp: This file contains the class definitions for SimpleFileFactory.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;

//This creates a file with the given file name
AbstractFile* SimpleFileFactory::createFile(string name) {
    string type = "   ";
    unsigned int i = 0;
    if (name.size() == 0) {
        return nullptr;
    }
    while (name[i] != '.' && i < name.size()) {
        ++i;
    }
    //Need to check what type of file to create and safely iterate through the string
    if (i < name.size()) {
        for (unsigned int j = 0; j < 3; ++j) {
            int index = i + j + 1;
            type[j] = name[index];
        }
        if (type == "txt") {
            AbstractFile* file = new TextFile(name);
            return file;
        }
        if (type == "img") {
            AbstractFile* file = new ImageFile(name);
            return file;
        }
    }
    return nullptr;

}