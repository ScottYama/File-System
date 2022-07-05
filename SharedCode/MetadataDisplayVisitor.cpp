/* MetadataDisplayVisitor.cpp: This file contains the class definitions for MetadataDisplayVisitor.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Allows the visitor to print out the metadata of the text file.
void MetadataDisplayVisitor::visit_TextFile(TextFile * file) {
	cout.width(25);
	cout << left << (*file).getName();
	cout.width(25);
	cout << left << "text ";
	cout.width(25);
	cout << left << (*file).getSize() << endl;
}
//Allows the visitor to print out the metadata of the image file.
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	cout.width(25);
	cout << left << (*file).getName();
	cout.width(25);
	cout << left << "image";
	cout.width(25);
	cout << left << (*file).getSize() << endl;
}
