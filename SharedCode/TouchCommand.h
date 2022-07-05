/* TouchCommand.h: This file contains the class declaration for TouchCommand, which inherits from the AbstractCommand
* interface. The touch command creates a new file and adds it to the file system.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
class TouchCommand : public AbstractCommand {
public:
	TouchCommand( AbstractFileSystem*, AbstractFileFactory*);
	~TouchCommand() = default;
	virtual void displayInfo();
	virtual int execute(std::string);

private:
	AbstractFileFactory* fileFactory;
	AbstractFileSystem* fileSystem;

};