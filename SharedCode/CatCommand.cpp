/* CatCommand.cpp: This file contains the class definitions for CatCommand. 
*/
#include "CatCommand.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>
using namespace std;
//Constructor
CatCommand::CatCommand(AbstractFileSystem* fileSys) : fileSystem(fileSys) {}
//Displays what the cat command does and how to invoke it
void CatCommand::displayInfo() {
	cout << "The Cat Command is used for concatenating files. It can be invoked with the command: cat <filename> [-a]." << endl;
}
//The execute function takes in an input an allows the user to add to the file. 
int CatCommand::execute(string param) {
	// Wrap the input in an istringstream to parse it into a filename and an optional append. 
	istringstream iss(param);
	string fileName;
	string append;
	if (iss >> fileName) {
		if (iss >> append) {
			//If -a is inputted at the end, we want to print out the file before appendingto the end of it. 
			//This doesn't work for .img files.
			if (append == "-a") {
				AbstractFile* file = fileSystem->openFile(fileName);
				if (file == nullptr) {
					return 21;
				}
				string type = "   ";
				int i = 0;
				while (fileName[i] != '.') {
					++i;
				}
				for (int j = 0; j < 3; ++j) {
					int index = i + j + 1;
					type[j] = fileName[index];
				}
				if (type == "img") {
					fileSystem->closeFile(file);
					return 23;
				}
				//print the contents
				vector<char> contents = file->read();
				for (unsigned int i = 0; i < contents.size(); ++i) {
					cout << contents[i];
				}
				cout << endl;
				//prompt the user for data
				cout << "Input data to append to the file, \":wq\" to save and quit, or \":q\" to quit without saving." << endl;
				string input;
				string temp;
				while (getline(cin, input)) {
					//if :q is inputted, close the file and return without saving.
					if (input == ":q") {
						fileSystem->closeFile(file);
						return 0;
					}
					//if :wq is inputted, add the inputted data to the file, close the file, then return.
					else if (input == ":wq") {
						vector<char> appending;
						for (unsigned int i = 0; i < temp.size() - 1; ++i) {
							appending.push_back(temp[i]);
						}
						file->append(appending);
						fileSystem->closeFile(file);
						return 0;
					}
					//Otherwise, keep adding the input to a temporary string
					else {
						temp += input;
						temp.push_back('\n');
					}
				}
			}
			else {
				return 22;
			}
		}
		//If -a isn't added, we want to replace the data in the file with the inputted data
		else {
			AbstractFile* file = fileSystem->openFile(fileName);
			if (file == nullptr) {
				return 21;
			}

			//prompt user for input
			cout << "Input data to write to the file, \":wq\" to save and quit, or \":q\" to quit without saving." << endl;
			string input;
			string temp;
			while (getline(cin, input)) {
				//if :q is inputted, close the file and return without saving.
				if (input == ":q") {
					fileSystem->closeFile(file);
					return 0;
				}
				//if :wq is inputted, write the inputted data to the file, close the file, then return.
				else if (input == ":wq") {
					vector<char> writing;
					for (unsigned int i = 0; i < temp.size() - 1; ++i) {
						writing.push_back(temp[i]);
					}
					file->write(writing);
					fileSystem->closeFile(file);
					return 0;
				}
				//Otherwise, keep adding the input to a temporary string
				else {
					temp += input;
					temp.push_back('\n');
				}
			}
		}
	}
	return 23;
}