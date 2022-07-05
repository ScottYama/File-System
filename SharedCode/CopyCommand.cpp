/* CopyCommand.cpp: This file contains the file definitions for the Copy Command Class
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "CopyCommand.h"
using namespace std;
#include <iostream>
#include <sstream>

//Constructor
CopyCommand::CopyCommand(AbstractFileSystem* fileSys) : fileSystem(fileSys) {}
//Displays what the copy command does and how to invoke it
void CopyCommand::displayInfo() {
	cout << "The Copy Command will copy an existing file in the file system and add the copy to the file system with a different name. It can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension>" << endl;

}
//In the execute commmand, the copy command creates a copy of a file and adds it to the file system.
int CopyCommand::execute(string param) {
	istringstream iss(param);
	string fileName;
	string copyName;
	string tempName;
	if (iss >> fileName >> copyName) {
		tempName = fileName;
		tempName.erase(tempName.end()-4, tempName.end());
		//check if the fileName and the copyName are the same
		if (tempName == copyName) {
			return 23;
		}
		AbstractFile* file = fileSystem->openFile(fileName);
		//Check if the file was created successfully
		if (file == nullptr) {
			return 21;
		}
		//Create a copy and add it to the file system
		AbstractFile* copy = file->clone(copyName);
		string name = copy->getName();
		int result = fileSystem->addFile(name, copy);
		if (result != 0) {
			fileSystem->closeFile(file);
			return 22;
		}
		fileSystem->closeFile(file);
		return 0;
	}
	return 23;
}