// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	AbstractFile * file = new TextFile("yeet");
	vector<char> a;
	a.push_back('a');
	a.push_back('b');
	a.push_back('c');
	(*file).write(a);
	(*file).read();
	vector<char> b;
	b.push_back('d');
	b.push_back('e');
	b.push_back('f');
	(*file).append(b);
	(*file).read();
	(*file).write(b);
	(*file).read();
	(*file).append(a);
	(*file).read();
	(*file).write(a);
	(*file).read();
	cout << "Name: " << (*file).getName() << ", Size: " << (*file).getSize() << endl;
	delete file;
}


