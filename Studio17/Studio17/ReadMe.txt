Answer the studio 17 questions here.
1.	Names: Jeremy Ouyang, Scott Yamamoto
2.	e:	The read() function should be protected.
	We created four new vectors called c, d, e, f each holding different char values and with different sizes. c is a correctly formatted image vector with only X and ' '(spaces)
	and has the last char of 3 matching the size of the image. d is another correctly formatted image vector but with image size 2 instead. e is an incorrectly formatted image 
	vector since the last char of 5 does not match the size 2 of the image. f is another incorrectly formatted image vector since it contains other chars besides X and ' '. After 
	writting c to a file named "pic" with file.write(c), we used file.read() to display the image, the name of the file, and the size of the vector and all this is displayed
	correctly. Then, we tried to use file.append(d) to add c and d and since append is not supported, when we use file.read() again and print out the name and size, the output
	is the same which is correct. Then we use file.write(d) which replaces the member vector "contents" with d and when we use file.read() again and print out the name and size,
	the output is correct since the image that corresponds to d is printed with the same file name but new size of 4. Then we tried writting and reading with vector e using 
	file.write(e) and file.read(). Since this image vector is formatted incorrectly with a size mismatch, the member vector "contents" is cleared and the member variable size is
	set to 0. This prints corrrectly with no image, same file name, and size equal to 0. Writting and reading f using file.write(f) and file.read() displayed the same correct output
	as with vector e since f is also formatted incorrectly with chars other than X and ' ' so the member vector "contents" is cleared and the size is set to 0.
	
	Code:
	int main()
	{
		ImageFile file = ImageFile("pic");
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

		return 0;
	}

	Terminal:
	  X
	 X
	X
	Name: pic, Size: 9
	  X
	 X
	X
	Name: pic, Size: 9
	 X
	X
	Name: pic, Size: 4
	Name: pic, Size: 0
	Name: pic, Size: 0

3.	The biggest benefit of programming a client to use an interface rather than a concrete class is that the code can be easily modified when using an interface. With a concrete
	class, making changes to the class can also change how the client code interacts with the class and its member functions and variables. This forces the client code to change
	as well as the class itself. However, when making changes using an interface, you can change/add classes that inherit from the interface. That way, since the client interacts
	with the interface and the interface remains the same, you do not need to change any of the client code.

4.	We would need to add code in the SimpleFileSystem class to the createFile() class that is spcific to the new concrete file type such as a MusicFile. This new file type would
	need to be declared and defined and inherit publicly from our AbstractFile class as well.

   