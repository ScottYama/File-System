/*AbstractFileFactory.h: This file contains the interface for file factories, which can create files by implementing the factory method.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once


#include "AbstractFileSystem.h"

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string) = 0;
};