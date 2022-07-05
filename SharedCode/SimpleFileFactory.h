/* SimpleFileFactory.h: This file contains the class declaration for the SimpleFileFactory, which inherits from the 
* AbstractFileFactory interface. This class allows for the creation of files through the factory method.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once

#include "AbstractFileFactory.h"


class SimpleFileFactory : public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string);
};