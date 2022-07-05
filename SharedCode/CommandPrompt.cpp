/* CommandPrompt.cpp: This file contains the class definitions for the CommandPrompt class.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "CommandPrompt.h"
using namespace std;
#include <iostream>
#include <sstream>
//Constructor
CommandPrompt::CommandPrompt():fileSystem(nullptr),fileFactory(nullptr){}
//Setter for the file System
void CommandPrompt::setFileSystem(AbstractFileSystem* fileSys) {
	fileSystem = fileSys;
}
//Setter for the File Factory
void CommandPrompt::setFileFactory(AbstractFileFactory* fileFact) {
	fileFactory = fileFact;
}
//This function adds a command to the command Objects map.
int CommandPrompt::addCommand(string command, AbstractCommand* commandptr) {
	if (commandObjects.count(command) == 0) {
		commandObjects.insert(pair<string,AbstractCommand*>(command, commandptr ));
		return 0;
	}
	return 11;
}
//This method prints out a list of the commands in the commandObjects map
void CommandPrompt::listCommands() {
	auto iterator = commandObjects.begin();
	while (iterator != commandObjects.end()) {
		cout << iterator->first << endl;
		++iterator;
	}
}
//This method prompts the user for input
string CommandPrompt::prompt() {
	cout << "Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command. " << endl;
	cout << "$    ";
	string input;
	while (getline(cin, input)) {
		if (input != "") {
			return input;
		}
	}
	return input;
}

//This method codes for the interface where the user interacts with the file system.
int CommandPrompt::run() {
	//This command keeps running until the user quits.
	while (1) {
		string input = prompt();
		if ("q" == input) {
			return 12;
		}
		//If help is inputted, list the commands.
		if (input == "help") {
			listCommands();
		}
		//Check how many strings are inputted
		bool singleString = true;
		for (unsigned int i = 0; i < input.size(); ++i) {
			if (input[i] == ' ') {
				singleString = false;
			}
		}
		//execute the command if it's a single string
		if (singleString && input != "help") {
			auto iterator = commandObjects.begin();
			bool commandExists = false;
			while (iterator != commandObjects.end()) {
				if (input == iterator->first) {
					string empty;
					int result = iterator->second->execute(empty);
					commandExists = true;
					if (result != 0) {
						cout << "The command failed." << endl;
					}
				}
				++iterator;

			}
			if (!commandExists) {
				cout << "This command doesn't exist." << endl;
			}
			
		}
		//If the input is more than one string, continue to parse the input and accordingly execute the correct function
		else {
			string word;
			//wrap the stirng in an input so it's easier to parse it into different words
			istringstream iss(input);
			if (iss >> word) {
				//if help is inputted, we want to display info of whatever command is entered after.
				if (word == "help") {
					string commandName;
					if (iss >> commandName) {
						bool commandExists = false;
						auto iterator = commandObjects.begin();
						while (iterator != commandObjects.end()) {
							if (commandName == iterator->first) {
								commandExists = true;
								iterator->second->displayInfo();
							}
							++iterator;
						}
						if (!commandExists) {
							cout << "This command does not exist." << endl;
						}
					}

				}
				//If something other than help is the first word inputted, we want to execute the command if it exists.
				else {
					bool commandExists = false;
					string secondWord;
					string remainingString;
					//Add the remaining strings together to input as the parameter in the execute method.
					if (iss >> secondWord) {
						remainingString += secondWord;
					}
					while (iss >> secondWord) {
						remainingString += " ";
						remainingString += secondWord;
					}
					auto iterator = commandObjects.begin();
					while (iterator != commandObjects.end()) {
						if (word == iterator->first) {
							string empty;
							commandExists = true;
							int result = iterator->second->execute(remainingString);
							if (result != 0) {
								cout << "The command failed." << endl;
							}
						}
						++iterator;
					}
					if (!commandExists) {
						cout << "This command does not exist." << endl;
					}
					
				}
			}
		}
	}
	return 0;
}