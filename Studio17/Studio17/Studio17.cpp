// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\ImageFile.h"
#include <iostream>
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\TextFile.h"


using namespace std;


int main()
{
	SimpleFileSystem sfs;
	ImageFile* img1 = new ImageFile("img1.img");
	TextFile* txt1 = new TextFile("txt1.txt");

	vector<char> vec1 = { ' ', 'X', ' ', 'X', '2' };
	vector<char> vec2 = { 'h','e','l','l','o' };
	vector<char> vec3 = { 'X', 'X', ' ', 'X', '2' };
	vector<char> vec4 = { 's','u','p' };

	sfs.addFile("img1.img", img1);
	sfs.addFile("txt1.txt", txt1);

	sfs.createFile("img2.img");
	sfs.createFile("txt2.txt");

	AbstractFile* abs1 = sfs.openFile("img1.img");
	abs1->write(vec1);
	abs1->read();
	AbstractFile* abs2 = sfs.openFile("txt1.txt");
	abs2->write(vec2);
	abs2->read();
	AbstractFile* abs3 = sfs.openFile("img2.img");
	abs3->write(vec3);
	abs3->read();
	AbstractFile* abs4 = sfs.openFile("txt2.txt");
	abs4->write(vec4);
	abs4->read();

	sfs.closeFile(abs1);
	sfs.closeFile(abs2);
	sfs.closeFile(abs3);
	sfs.closeFile(abs4);

	sfs.deleteFile("img1.img");
	sfs.deleteFile("txt1.txt");
	sfs.deleteFile("img2.img");
	sfs.deleteFile("txt2.txt");
	
	


	/*ImageFile file = ImageFile("pic");
	vector<char> c;
	c.push_back('X');
	c.push_back(' ');
	c.push_back(' ');
	c.push_back(' ');
	c.push_back('X');
	c.push_back(' ');
	c.push_back(' ');
	c.push_back(' ');
	c.push_back('X');
	c.push_back('3');
	file.write(c);
	file.read();
	cout << "Name: " << file.getName() << ", Size: " << file.getSize() << endl;
	vector<char> d;
	d.push_back('X');
	d.push_back(' ');
	d.push_back(' ');
	d.push_back('X');
	d.push_back('2');
	file.append(d);
	file.read();
	cout << "Name: " << file.getName() << ", Size: " << file.getSize() << endl;
	file.write(d);
	file.read();
	cout << "Name: " << file.getName() << ", Size: " << file.getSize() << endl;
	vector<char> e;
	e.push_back('X');
	e.push_back(' ');
	e.push_back(' ');
	e.push_back('X');
	e.push_back('5');
	file.write(e);
	file.read();
	cout << "Name: " << file.getName() << ", Size: " << file.getSize() << endl;
	vector<char> f;
	f.push_back('X');
	f.push_back('O');
	f.push_back('O');
	f.push_back('X');
	f.push_back('2');
	file.write(f);
	file.read(); 
	cout << "Name: " << file.getName() << ", Size: " << file.getSize() << endl;
	*/

	return 0;
}

