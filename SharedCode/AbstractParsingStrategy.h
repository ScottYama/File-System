/*AbstractParsingStrategy.h: This file contains the declaration for the parsing strategy interface.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include <vector>
#include <string>
class AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) = 0;
};