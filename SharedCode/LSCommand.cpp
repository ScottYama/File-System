/* LSCommand.cpp: This file contains the class definitions for LSCommand.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
using namespace std;
#include <set>
#include <iostream>
#include <iomanip>
//Constructor
LSCommand::LSCommand(AbstractFileSystem* fileSys):fileSystem(fileSys){}
//Displays what the LS command does and how to invoke it
void LSCommand::displayInfo() {
	cout << "LSCommand can be invoked with the command : 'ls' to show the file names or 'ls -m' to show the file names and the file metadata" << endl;
}
//The execute function allows LSCommand to display all the file names in the file system
int LSCommand::execute(string param) {
	set<string> names = fileSystem->getFileNames();
	auto iterator = names.begin();
	//If nothing else is inputted into the terminal, display the files two per line.
	if (param == "") {
		bool even = true;
		while (iterator != names.end()) {
			cout.width(25);
			cout << left << *iterator;
			even = !even;
			if (even) {
				cout << endl;
			}
			++iterator;
		}
		if (!even) {
			cout << endl;
		}
		return 0;
	}
	//If -m is included in the command line, display the metadata of each file.
	else if(param=="-m"){
		AbstractFileVisitor * visitor = new MetadataDisplayVisitor();
		while (iterator != names.end()) {
			AbstractFile* file = fileSystem->openFile(*iterator);
			file->accept(visitor);
			fileSystem->closeFile(file);
			++iterator;
		}
		return 0;
	}
	else {
		return 16;
	}
}