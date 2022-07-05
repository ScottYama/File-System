/*AbstractFileSystem.h: This file contains the declaration for the File System interface.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include <string>
#include "AbstractFile.h"
#include <set>


class AbstractFileSystem {
public:
	virtual int addFile(std::string, AbstractFile*) = 0;
	virtual int deleteFile(std::string) = 0;
	virtual AbstractFile* openFile(std::string) = 0;
	virtual int closeFile(AbstractFile*) = 0;
	virtual std::set<std::string> getFileNames() = 0;
};