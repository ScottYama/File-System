/* AbstractFile.h: This file creates an interface for the different types of file that will exist in the file system.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include <vector>
#include <string>
#include "AbstractFileVisitor.h"


class AbstractFile {
public:
	virtual std::vector<char> read() =0;
	virtual int write(std::vector<char>)=0;
	virtual int append(std::vector<char>)=0;
	virtual unsigned int getSize()=0;
	virtual std::string getName()=0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*)=0;
	virtual AbstractFile* clone(std::string) = 0;
};