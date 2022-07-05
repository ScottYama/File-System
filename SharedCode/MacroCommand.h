/* MacroCommand.h: This file contains the class declaration for MacroCommand class, which inherits from the AbstractCommand
* interface. Macrocommand allows for more than one command to be run with one command call in the terminal.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
class MacroCommand :public AbstractCommand {
public:
	MacroCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
private:
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* strat;
	AbstractFileSystem* fileSystem;
};