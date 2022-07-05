// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\ImageFile.h"
#include <iostream>
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\TextFile.h"

using namespace std;

int main()
{
	AbstractFileSystem* fileSystem = new SimpleFileSystem;
	AbstractFileFactory* fileFactory = new SimpleFileFactory;

	vector<char> vec1 = { ' ', 'X', ' ', 'X', '2' };
	vector<char> vec2 = { 'h','e','l','l','o' };

	AbstractFile* img1 = fileFactory->createFile("img1.img");
	AbstractFile* txt1 = fileFactory->createFile("txt1.txt");

	fileSystem->addFile("img1.img", img1);
	fileSystem->addFile("txt1.txt", txt1);

	AbstractFile* abs1 = fileSystem->openFile("img1.img");
	abs1->write(vec1);
	abs1->read();
	AbstractFile* abs2 = fileSystem->openFile("txt1.txt");
	abs2->write(vec2);
	abs2->read();

	return 0;
}
