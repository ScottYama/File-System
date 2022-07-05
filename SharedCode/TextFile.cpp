/*TextFile.cpp: This file contains the class definitions for TextFile.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "TextFile.h"
#include <iostream>
using namespace std;
//Constructor
TextFile::TextFile(string str):name(str) {}
//Return the size of the text file
unsigned int TextFile::getSize() {
	return (unsigned int) contents.size();
}
//Return the name of the text file
string TextFile::getName() {
	return name;
}
//Write to the text file
int TextFile::write(vector<char> newStuff) {
	contents = newStuff;
	return 0;
}
//Append to the text file
int TextFile::append(vector<char> newStuff) {
	for (unsigned int i = 0; i < newStuff.size(); ++i) {
		contents.push_back(newStuff[i]);
	}
	return 0;
}
//Return the contents of the text file
vector<char> TextFile::read() {
	return contents;
}
//Allow a visitor to visit the text file
void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_TextFile(this);
}

//Clone the text file for use in the Copy Command.
AbstractFile* TextFile::clone(string newName) {
	string temp = this->getName();
	this->name = newName+".txt";
	AbstractFile* copy = new TextFile(*this);
	this->name = temp;
	return copy;
}