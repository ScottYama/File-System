/* CopyCommand.h: This file contains the class declaration for Copy Command, which inherits from the AbstractCommand interface.
* Copy Command allows for files to be copied and placed in the file system.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CopyCommand :public AbstractCommand {
public:
	CopyCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
};
