/* PasswordProxy.cpp: This file contains the class definitions for PasswordProxy.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#include "PasswordProxy.h"
using namespace std;
#include <iostream>
//Constructor
PasswordProxy::PasswordProxy(AbstractFile* newFile,string newPassword):file(newFile),password(newPassword){}
//Destructor
PasswordProxy::~PasswordProxy() {
	delete file;
}
//Prompt the user to input the password
string PasswordProxy::passwordPrompt() {
	string input;
	cout << "Input Password" << endl;
	if (cin >> input) {
		return input;
	}
	return "";
}
//check if the password is correct
bool PasswordProxy::checkPassword(string pass) {
	return pass == password;
}
//Read the contents of the file
vector<char> PasswordProxy::read() {
	string password = passwordPrompt();
	vector<char> contents;
	if (checkPassword(password)) {
		contents= file->read();
	}
	return contents;
}
//Write to the file
int PasswordProxy::write(vector<char> newContents) {
	string password = passwordPrompt();
	if (checkPassword(password)) {
		return file->write(newContents);
	}
	return 10;
}
//Append to the end of the file
int PasswordProxy::append(vector<char> newContents) {
	string password = passwordPrompt();
	if (checkPassword(password)) {
		return file->append(newContents);
	}
	return 10;
}
//Get the size of the file
unsigned int PasswordProxy::getSize() {
	return file->getSize();
}
//Get the name of the file
string PasswordProxy::getName() {
	return file->getName();
}
//Allow a visitor to visit the file
void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	string password = passwordPrompt();
	if (checkPassword(password)) {
		return file->accept(visitor);
	}
}
//Clone the PasswordProxy, used for the CopyCommand
AbstractFile* PasswordProxy::clone(string newName) {
	AbstractFile * copy = file->clone(newName);
	AbstractFile* copyProxy = new PasswordProxy(copy,this->password);
	return copyProxy;
}