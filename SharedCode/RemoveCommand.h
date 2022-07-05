/* RemoveCommand.h: This file contains the class declaration for RemoveCommand class, which inherits from the AbstractCommand
* interface. The remove command removes a file with the provided name from the file system.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
class RemoveCommand :public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
};
