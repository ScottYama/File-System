Lab 5 Readme:
Group members: Jeremy Ouyang, Scott Yamamoto
Work was split up evenly as we worked through each step of the studios together. When we got to the lab, Jeremy did a bit more of
the "first draft" of the coding, Scott worked more on the testing and debugging part, and we worked together to fix errors that 
we came across.

Errors/bugs:
	1.	The only major error we ran into was that in several of our commands, when we were opening files, we forgot to close the file, 
	resulting in it being inaccessible in later commands. This fix was pretty easy as we just added a call to close file before 
	the applicable return statements.

Testing:
	
	1.	This example shows the help input when used alone and with each command to show the command's use (we decided to have both of our MacroCommands, tc and rn, say the same thing)

		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    help
		cat
		tc
		cp
		ds
		ls
		rm
		rn
		touch
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    help cat
		The Cat Command is used for concatenating files. It can be invoked with the command: cat <filename> [-a].
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    help tc
		The Macro Command can execute multiple commands.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    help cp
		The Copy Command will copy an existing file in the file system and add the copy to the file system with a different name. It can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension>
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    help ds
		The Display Command opens a file and displays its contents. It can be invoked with the command: ds <filename> [-d]
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    help ls
		LSCommand can be invoked with the command : 'ls' to show the file names or 'ls -m' to show the file names and the file metadata
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    help rm
		Remove removes a file with the provided name from the file system. It can be invoked with the command: rm <filename>.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    help rn
		The Macro Command can execute multiple commands.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    help touch
		Touch creates a file, touch can be invoked with the command : touch <filename>
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$


	2.	This example shows files being created incorrectly using the TouchCommand (with exception of first "touch text.txt" which is used to show no duplicate files)
	
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch invalid
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch invalid.jpg
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch invalid .img
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch text.txt
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch text.txt
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$


	3.	This example shows files with and without a password being created using TouchCommnad and removed using RemoveCommand. This also shows the LSCommand used with and without "-m"

		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch text.txt
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch image.img
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch passwordfile.txt -p
		Input Password:
		1234
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls
		image.img                passwordfile.txt
		text.txt
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls -m
		image.img                image                    0
		Input Password
		1234
		passwordfile.txt         text                     0
		text.txt                 text                     0
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    rm passwordfile.txt
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls
		image.img                text.txt
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls -m
		image.img                image                    0
		text.txt                 text                     0
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$


	4.	This example shows the CatCommand to append or write to a text file.

		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch text.txt
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat text.txt
		Input data to write to the file, ":wq" to save and quit, or ":q" to quit without saving.
		hello
		:wq
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls -m
		text.txt                 text                     5
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat text.txt -a
		hello
		Input data to append to the file, ":wq" to save and quit, or ":q" to quit without saving.
		world
		:wq
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat text.txt -a
		helloworld
		Input data to append to the file, ":wq" to save and quit, or ":q" to quit without saving.
		hi friend
		:q
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds text.txt
		helloworld
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls -m
		text.txt                 text                     10
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat text.txt
		Input data to write to the file, ":wq" to save and quit, or ":q" to quit without saving.
		howdy folks
		hows it going?
		:wq
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls -m
		text.txt                 text                     26
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds text.txt
		howdy folks
		hows it going?


	5.	This example shows the CatCommand with an image file and a password. This shows multiple incorrect inputs for the image file, a correct input, and shows how you cant append to an image file.

		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch passwordfile.img -p
		Input Password:
		1234
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat passwordfile.img
		Input data to write to the file, ":wq" to save and quit, or ":q" to quit without saving.
		XXXX
		:wq
		Input Password
		1234
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds passwordfile.img
		Input Password
		1234
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat passwordfile.img
		Input data to write to the file, ":wq" to save and quit, or ":q" to quit without saving.
		XXX2
		:wq
		Input Password
		1234
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds passwordfile.img
		Input Password
		1234
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat passwordfile.img
		Input data to write to the file, ":wq" to save and quit, or ":q" to quit without saving.
		XOXO2
		:wq
		Input Password
		1234
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds passwordfile.img
		Input Password
		1234
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat passwordfile.img
		Input data to write to the file, ":wq" to save and quit, or ":q" to quit without saving.
		XXXX2
		:wq
		Input Password
		1234
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds passwordfile.img
		Input Password
		1234
		XX
		XX
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds passwordfile.img -d
		Input Password
		1234
		XXXX
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat passwordfile.img -a
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds passwordfile.img
		Input Password
		1234
		XX
		XX
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$


	6.	This example shows the CopyCommand and how a copy of a file cannot be created if the new copy file has the same name as an existing file

		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch image.img
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch image2.img
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat image.img
		Input data to write to the file, ":wq" to save and quit, or ":q" to quit without saving.
		XXX   XXX3
		:wq
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cat image2.img
		Input data to write to the file, ":wq" to save and quit, or ":q" to quit without saving.
		 XX 2
		:wq
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls -m
		image.img                image                    9
		image2.img               image                    4
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cp image.img image
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cp image.img image2
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    cp image.img image_copy
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls -m
		image.img                image                    9
		image2.img               image                    4
		image_copy.img           image                    9
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds image.img
		XXX

		XXX
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds image_copy.img
		XXX

		XXX
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$
		

	7.	This example shows the rename MacroCommand and how a file cannot be renamed to itself or renamed with the same name as another file that exists

		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch h.img
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch f.txt
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    touch a.txt
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    rn f.txt f
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    rn f.txt a
		The command failed.
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    rn f.txt b
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls
		a.txt                    b.txt
		h.img
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    rn b.txt f
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls
		a.txt                    f.txt
		h.img
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$



MacroCommand of choice: touch + cat
	This command can be invoked with the command: tc <filename>

	Test: This test shows the touch + cat MacroCommand as a file is created and the user is immediately prompted to write into the file
		
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    tc file.txt
		Input data to write to the file, ":wq" to save and quit, or ":q" to quit without saving.
		asdf
		1234
		:wq
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ls
		file.txt
		Enter a valid command, q to quit, help for a list of commands, or help <command name> for details about a specific command.
		$    ds file.txt
		asdf
		1234
