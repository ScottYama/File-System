/* CreateEditParsingStrategy.cpp: This file contains the class definitions for the CreateEditParsingStrategy class.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "CreateEditParsingStrategy.h"
#include <string>
#include <vector>
using namespace std;
//This command parses the inputs so that the touch + cat macrocommand will work successfully
vector<string> CreateEditParsingStrategy::parse(string param) {
	vector<string> inputs;
	inputs.push_back(param);
	inputs.push_back(param);
	return inputs;
}