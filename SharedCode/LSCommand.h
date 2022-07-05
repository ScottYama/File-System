/* LSCommand.h: This file contains the class declaration for LSCommand class, which inherits from the AbstractCommand
* interface. The ls command prints out the file system's files.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class LSCommand :public AbstractCommand {
public:
	LSCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
};