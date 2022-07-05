/* CreateEditParsingStrategy.h: This file contains the class declaration for CreateEditParsingStrategy, which inherits from
* the AbstractParsingStrategy interface. This parsing strategy helps create the MacroCommand Touch + cat, which allows the 
* user to create a file and immediately edit it.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "AbstractParsingStrategy.h"

class CreateEditParsingStrategy :public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string);
};