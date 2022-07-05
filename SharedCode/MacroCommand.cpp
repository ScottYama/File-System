/* MacroCommand.cpp: This file contains the class definitions for MacroCommand.
* Authors: Jeremy Ouyang, Scott Yamamoto
*/
#include "MacroCommand.h"
#include <iostream>
using namespace std;
#include <vector>
//Constructor
MacroCommand::MacroCommand(AbstractFileSystem* fileSys):strat(nullptr),fileSystem(fileSys) {}
//Displays what the MacroCommand does
void MacroCommand::displayInfo() {
	cout << "The Macro Command can execute multiple commands." << endl;
}
//The execute command allows MacroCommand to run through the vectors of strings and of commands to execute multiple commands.
int MacroCommand::execute(string param) {
	vector<string> inputs = strat->parse(param);
	for (unsigned int i = 0; i < inputs.size(); ++i) {
		int result = commands[i]->execute(inputs[i]);
		if (result != 0) {
			return result;
		}
	}
	return 0;
}
//Add commands to the MacroCommand
void MacroCommand::addCommand(AbstractCommand* command) {
	commands.push_back(command);
}
//Setter for the Parse Strategy for the MacroCommand
void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
	strat = strategy;
}