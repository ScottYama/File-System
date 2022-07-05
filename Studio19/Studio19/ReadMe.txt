studio 19 answers here
1.	Jeremy Ouyang, Scott Yamamoto
2.	We tested one text file with 'h','e','l','l','o' and changed the first char to 'm'. Then we tested one image file with  ' ', 'X', ' ', 'X', '2' and changed the first char to 'X'.
	code:
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

		return 0;
	}

	terminal:
	mello
	XX X
3.	The visitor is first created in the main method. Then they take a pointer to the correct file type and use it to access the necessary variables in the file type class to
	display them. This visitor method is used by the accept method of each file type to print out the file.
4.	The visitor pattern uses delegation since we create a new abstract class that holds holds multiple ways of reading the files. Therefore, we do not need to declare and define
	each different type of read within each concrete file type class.
5.	If we have a lot of unique visitors and we decided to add another concrete file type that should be visble, we would need to create code for the new class, change the visitor 
	interface and all of the concrete visitors. A bad time to use this pattern is when there are many types of file types since the visitor classes will get cluttered from all
	of the different file types.