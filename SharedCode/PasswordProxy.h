/* PasswordProxy.h: This file contains the declaration for the PasswordProxy class, which allows files to be password protected.
* It inherits from the AbstractFile interface. 
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractFile.h"
class PasswordProxy: public AbstractFile {
public:
	PasswordProxy(AbstractFile*, std::string);
	~PasswordProxy();
	virtual std::vector<char> read() ;
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>) ;
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(std::string);
protected:
	std::string passwordPrompt();
	bool checkPassword(std::string);
private:
	AbstractFile* file;
	std::string password;
	
};