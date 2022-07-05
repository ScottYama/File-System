/* CatCommand.h: This file contains the declaration of the Cat Command, which allows the user to add to a file.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand :public AbstractCommand {
public:
	CatCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
};
