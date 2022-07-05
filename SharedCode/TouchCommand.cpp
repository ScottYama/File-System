/* TouchCommand.cpp: This file contains the class definitions for TouchCommand.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "TouchCommand.h"
#include "PasswordProxy.h"
#include <iostream>
using namespace std;
#include <sstream>
//Constructor
TouchCommand::TouchCommand( AbstractFileSystem* fileSys, AbstractFileFactory* fileFact): fileFactory(fileFact),fileSystem(fileSys){}

//Displays what the Touch command does and how to invoke it
void TouchCommand::displayInfo() {
	cout << "Touch creates a file, touch can be invoked with the command : touch <filename>" << endl;
}

//The execute function allows the Touch Command to create a new file
int TouchCommand::execute(string param) {
	istringstream iss(param);
	string first;
	string second;
	if (iss >> first) {
		if (iss >> second) {
			// If -p is inputted, create a file with a password
			if (second == "-p") {
				AbstractFile* file = fileFactory->createFile(first);
				cout << "Input Password: " << endl;
				string password;
				cin >> password;
				AbstractFile* passFile = new PasswordProxy(file, password);
				int result = fileSystem->addFile(first, passFile);
				if (result != 0) {
					delete passFile;
					delete file;
					return 18;
				}
				else {
					return 0;
				}
			}
			else {
				return 14;
			}
		}
		else {
			//If nothing else is inputted, create a regular file
			AbstractFile* file = fileFactory->createFile(first);
			if (file != nullptr) {
				int result = fileSystem->addFile(first, file);
				if (result != 0) {
					delete file;
					return 15;
				}
				else {
					return 0;
				}
			}
		}
	}
	return 23;
}