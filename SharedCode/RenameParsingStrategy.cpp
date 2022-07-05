/* RenameParsingStrategy.cpp: This file contains the class declarations for RenameParsingStrategy.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "RenameParsingStrategy.h"
using namespace std;
#include <string>
#include <vector>
#include <sstream>
//The parse method parses the parameter into correct strings to use for the rename command.
vector<string> RenameParsingStrategy::parse(string param) {
	istringstream iss(param);
	string file;
	string rename;
	vector<string> inputs;
	if (iss >> file >> rename) {
		inputs.push_back(file+" "+rename);
		inputs.push_back(file);
	}
	return inputs;
	
}