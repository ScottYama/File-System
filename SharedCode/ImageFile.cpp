/* ImageFile.cpp: This file contains the class definitions for ImageFile.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "ImageFile.h"
#include <iostream>

using namespace std;
//Constructor
ImageFile::ImageFile(string s):size(0), name(s) {}
//Return the size of the file
unsigned int ImageFile::getSize() {
	return (unsigned int)contents.size();
}
//Return the name of the file
string ImageFile::getName() {
	return name;
}
//Write data to the file
int ImageFile::write(vector<char> input) {
	//Check if the size and the input size match
	size = input[input.size() - 1];
	int area = (size - 48)* (size - 48);
	contents.erase(contents.begin(),contents.end());
	if (area != input.size() - 1) {
		size = '0';
		return 1;
	}
	//Check if the input has valid characters
	for (unsigned int i = 0; i < input.size() - 1; ++i) {
		if (input[i] != 'X' && input[i] != ' ') {
			size = '0';
			return 2;
		}
	}
	input.pop_back();
	contents = input;
	return 0;
}
//Image File does not support append
int ImageFile::append(vector<char>) {
	return 3;
}
//Return the contents of the ImageFile with read()
vector<char> ImageFile::read() {
	return contents;
}
//Allow a visitor to visit the Image File
void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);
}
//This method clones the image file to be used in Copy command
AbstractFile* ImageFile::clone(string newName) {
	string temp = this->getName();
	this->name = newName + ".img";
	AbstractFile* copy = new ImageFile(*this);
	this->name = temp;
	return copy;
}