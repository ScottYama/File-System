/* ImageFile.h: This file contains the Image file class declaration, which inherits from the AbstractFile interface. 
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractFile.h"

class ImageFile : public AbstractFile {
public:
	ImageFile(std::string);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual std::vector<char> read();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(std::string);
private:
	std::string name;
	std::vector<char> contents;
	char size;
};