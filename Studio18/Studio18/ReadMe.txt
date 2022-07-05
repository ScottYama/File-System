1.	Jeremy Ouyang, Scott Yamamoto
2.	The factory method essentially is a strategy which uses an object to create other objects. It would be easy to create a new file system implementation that creates different
	file types than the SimpleFileSystem because the user only interacts with the AbstractFileSystem interface so the whichever file system is needed will be called. Delete the 
	createFile() from SimpleFileSystem, move it to another class and modify it to create the new concrete file type. 
3.	The advantage of the abstract factory pattern is that any file system can create any file type. One disadvantage is that it is more tedious to code. You would want to create 
	a new concrete file factory class when you have multiple concrete file systems that work with the same file types. Only the createFile method of the file factory must be 
	modified if a new file type is introduced. Yes, the same facotry can be used to create files for both file system implementations that manage the same types of files. Yes,
	as long as the file facotry contains code to create every type of file managed by both file system implementations. 
4.	code:
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

	terminal:
	 X
	 X
	hello

5.	No, the SimpleFileSystem does not depend on any concrete file types. The SimpleFileSystem only depends on the AbstractFile interface now.
