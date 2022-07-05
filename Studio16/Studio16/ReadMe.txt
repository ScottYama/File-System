Answer studio 16 questions here
1. Names: Jeremy Ouyang, Scott Yamamoto
2. To declare an interface, you create a class with only abstract member functions (pure virtual functions).
3. a: This is an example of interface inheritance.
   b: These two member variables should be private. 
4. We created two vectors of chars, a and b. a contains abc and b contains def. After writing a to the file, named "yeet,"
we used file.read() to print out the file, which occurs correctly. Then, we used file.append(b) to append vector b onto the end 
of contents in yeet. The resulting output from file.read() is correct, as it prints out "abcdef". Then, we test file.write(b),
and file.read() prints out the correct output as file.write replaces the contents member variable with the input parameter of write().
We then test the append and write method again and the methods continue working as expected (file.append(a) and file.write(b). 
Finally, we print out the file name with getName() and the size of the contents variable with getSize(), which both output courrectly.

Code:
int main(int argc, char* argv[])
{
	TextFile file = TextFile("yeet");
	vector<char> a;
	a.push_back('a');
	a.push_back('b');
	a.push_back('c');
	file.write(a);
	file.read();
	vector<char> b;
	b.push_back('d');
	b.push_back('e');
	b.push_back('f');
	file.append(b);
	file.read();
	file.write(b);
	file.read();
	file.append(a);
	file.read();
	file.write(a);
	file.read();
	cout << "Name: " << file.getName() << ", Size: " << file.getSize() << endl;
	
}

Terminal:
H:\repos\cse332s-sp22-wustl\Final\Studio16\x64\Debug>Studio16.exe
abc
abcdef
def
defabc
abc
Name: yeet, Size: 3

5. In order to have the file object interact with any arbitrary file type, we must make it a pointer to the AbstractFile
interface. It must be a pointer because AbstractFile does not have a defined constructor, so the compiler doesn't know it's 
definition at compile-time, and it is determined at run-time. Because of this, we need to store the object on the stack, 
so we include the "new" keyword with the TextFile constructor. Then, each time the file object is used for a method, it needs
to be dereferenced.

Code:
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

Terminal: 
H:\repos\cse332s-sp22-wustl\Final\Studio16\x64\Debug>Studio16.exe
abc
abcdef
def
defabc
abc
Name: yeet, Size: 3