/*BasicDisplayVisitor.cpp: This file contains the class definition for BasicDisplayVisitor. 
* Authors: Jeremy Ouyang, Scott Yamomoto
*/

#include "BasicDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;
#include <vector>
#include <iostream>
//This command allows the visitor to print out the contents of a text file.
void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
	vector<char> contents = file->read();
	for (unsigned int i = 0; i < contents.size(); ++i) {
		cout << contents[i];
	}
	cout << endl;
}

//This allows the visitor to print out the contents of an Image File
void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
	vector<char> contents = file->read();
	int index;
	
	int size = (int)pow((double)file->getSize(), 0.5);
	for (int y = size-1; y >-1; --y) {
		for (int x = 0; x < size; ++x) {
			index = y * size + x;
			cout << contents[index];
		}
		cout << endl;
	}
}
