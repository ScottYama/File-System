// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\ImageFile.h"
#include <iostream>
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"

using namespace std;

int main()
{
	AbstractFileSystem* fileSystem = new SimpleFileSystem;
	AbstractFileFactory* fileFactory = new SimpleFileFactory;

	vector<char> vec1 = { 'h','e','l','l','o' };
	vector<char> vec2 = { ' ', 'X', ' ', 'X', '2' };

	AbstractFile* txt1 = fileFactory->createFile("txt1.txt");
	AbstractFile* img1 = fileFactory->createFile("img1.img");

	fileSystem->addFile("txt1.txt", txt1);
	fileSystem->addFile("img1.img", img1);

	AbstractFile* abs1 = fileSystem->openFile("txt1.txt");
	abs1->write(vec1);
	vector<char> fileContents = abs1->read();
	AbstractFile* abs2 = fileSystem->openFile("img1.img");
	abs2->write(vec2);
	vector<char> fileContents2 = abs2->read();


	fileContents[0] = 'm';
	fileContents2[0] = 'X';
	char fileSize = (char)(pow(fileContents2.size(), .5) + 48);
	fileContents2.push_back(fileSize);


	abs1->write(fileContents);
	fileContents = abs1->read();
	abs2->write(fileContents2);
	fileContents2 = abs2->read();


	for (unsigned int i = 0; i < fileContents.size(); ++i) {
		cout << fileContents[i];
	}
	cout << endl;

	for (unsigned int j = 0; j < fileContents2.size(); ++j) {
		cout << fileContents2[j];
	}
	cout << endl;


	BasicDisplayVisitor * visitor = new BasicDisplayVisitor();
	TextFile* txt2 = new TextFile("txt2.txt");
	txt2->write(vec1);
	ImageFile* img2 = new ImageFile("img2.img");
	img2->write(vec2);
	txt2->accept(visitor);
	img2->accept(visitor);

	return 0;
}
