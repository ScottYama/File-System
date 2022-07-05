/* TextFile.h: This file contains the declaration for the TextFile class, which inherits the AbstractFile interface.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
	TextFile(std::string);
	virtual std::vector<char> read();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(std::string);
private:
	std::vector<char> contents;
	std::string name;
};