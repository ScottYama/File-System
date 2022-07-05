/* DisplayCommand.h: This file contains the class declaration for DisplayCommand class, which inherits from the AbstractCommand
* interface. The display command opens a file and displays it contents. 
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
class DisplayCommand :public AbstractCommand {
public:
	DisplayCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
};