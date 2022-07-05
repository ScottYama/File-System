// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there. We test the methods and classes
// that we built in the main method
// Authors: Jeremy Ouyang, Scott Yamomoto
//

#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\CatCommand.h"
#include "..\..\\SharedCode\DisplayCommand.h"
#include "..\..\\SharedCode\CopyCommand.h"
#include "..\..\\SharedCode\MacroCommand.h"
#include "..\..\\SharedCode\RenameParsingStrategy.h"
#include "..\..\\SharedCode\CreateEditParsingStrategy.h"



using namespace std;




int main()
{
	//set up file system, file factory, and commands
	SimpleFileSystem* sfs = new SimpleFileSystem;
	SimpleFileFactory* sff = new SimpleFileFactory;
	TouchCommand* touch = new TouchCommand(sfs, sff);
	LSCommand* ls = new LSCommand(sfs);
	RemoveCommand* rm = new RemoveCommand(sfs);
	CatCommand* cat = new CatCommand(sfs);
	DisplayCommand* ds = new DisplayCommand(sfs);
	CopyCommand* cp = new CopyCommand(sfs);
	MacroCommand* rn = new MacroCommand(sfs);
	MacroCommand* tc = new MacroCommand(sfs);
	RenameParsingStrategy* rps = new RenameParsingStrategy;
	rn->setParseStrategy(rps);
	rn->addCommand(cp);
	rn->addCommand(rm);
	CreateEditParsingStrategy* ceps = new CreateEditParsingStrategy;
	tc->setParseStrategy(ceps);
	tc->addCommand(touch);
	tc->addCommand(cat);

	//set up and run command prompt with all of the commands
	CommandPrompt ComPrompt;
	ComPrompt.setFileSystem(sfs);
	ComPrompt.setFileFactory(sff);
	ComPrompt.addCommand("ls", ls);
	ComPrompt.addCommand("touch", touch);
	ComPrompt.addCommand("rm", rm);
	ComPrompt.addCommand("cat", cat);
	ComPrompt.addCommand("ds", ds);
	ComPrompt.addCommand("cp", cp);
	ComPrompt.addCommand("rn", rn);
	ComPrompt.addCommand("tc", tc);
	ComPrompt.run();


	return 0;
}


