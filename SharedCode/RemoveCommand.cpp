/* RemoveCommand.cpp: This file contains the class definitions for RemoveCommand.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "RemoveCommand.h"
using namespace std;
#include <iostream>
//Constructor
RemoveCommand::RemoveCommand(AbstractFileSystem*fileSys):fileSystem(fileSys){}
//The execute function deletes the inputted file.
int RemoveCommand::execute(string param) {
	if (param == "") {
		return 17;
	}
	return fileSystem->deleteFile(param);
}
//Displays what the remove command does and how to invoke it
void RemoveCommand::displayInfo() {
	cout << "Remove removes a file with the provided name from the file system. It can be invoked with the command: rm <filename>." << endl;
}