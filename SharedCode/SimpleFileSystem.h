/* SimpleFileSystem.h: This file contains the class declaration for SimpleFileSystem, which inherits the AbstractFileSystem interface.
* This is the file system to which we will add, open, and delete files. 
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once

#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(std::string, AbstractFile*);
	virtual int deleteFile(std::string);
	virtual AbstractFile* openFile(std::string);
	virtual int closeFile(AbstractFile*);
	virtual std::set<std::string> getFileNames();
private:
	std::map<std::string, AbstractFile*> m;
	std::set<AbstractFile*> s;
};