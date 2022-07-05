/* RenameParsingStrategy.h: This file contains the declaration for the class RenameParsingStrategy, which inherits from the 
* AbstractParsingStrategy interface. This contains the method parse which is used in the rename MacroCommand.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/

#pragma once
#include "AbstractParsingStrategy.h"
class RenameParsingStrategy :public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string);
};