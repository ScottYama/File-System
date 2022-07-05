/* DisplayCommand.cpp: This file contains the class definitions for the DisplayCommand class.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>
using namespace std;
//Constructor
DisplayCommand::DisplayCommand(AbstractFileSystem* fileSys) : fileSystem(fileSys) {}
//Displays what the copy command does and how to invoke it
void DisplayCommand::displayInfo() {
	cout << "The Display Command opens a file and displays its contents. It can be invoked with the command: ds <filename> [-d]" << endl;
}
//The execute function displays the contents on the file
int DisplayCommand::execute(string param) {
	istringstream iss(param);
	string fileName;
	string display;
	if (iss >> fileName) {
		if (iss >> display) {
			//If the optional -d is included, only print the data of the file
			if (display == "-d") {
				AbstractFile* file = fileSystem->openFile(fileName);
				if (file == nullptr) {
					return 21;
				}
				vector<char> contents = file->read();
				for (unsigned int i = 0; i < contents.size(); ++i) {
					cout << contents[i];
				}
				cout << endl;
				fileSystem->closeFile(file);
				return 0;
			}
			else {
				return 19;
			}
		}
		//If the input doesn't include -d, we use the basic display visitor to print out the contents.
		AbstractFile* file = fileSystem->openFile(fileName);
		if (file == nullptr) {
			return 21;
		}
		AbstractFileVisitor* visitor = new BasicDisplayVisitor();
		file->accept(visitor);
		fileSystem->closeFile(file);
		delete visitor;
		return 0;
	}
	
	return 20;
}