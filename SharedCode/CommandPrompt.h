/* CommandPrompt.h: This file contains the declaration for the CommandPrompt class, which will be the user interface for our 
* file system. 
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include <map>
#include <string>
class CommandPrompt {
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	std::string prompt();

private:
	std::map<std::string, AbstractCommand*> commandObjects;
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
};