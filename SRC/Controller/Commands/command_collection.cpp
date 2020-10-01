#include "command_collection.h"
#include "../../MyLibrary/Exceptions/invalid_command.h"
#include "load.h"
#include "save.h"
#include "new.h"
#include "quit.h"
#include "len.h"
#include "dup.h"
#include "rename.h"
#include "help.h"
#include "find.h"
#include "del.h"
#include "pair.h"


HashMap<SharedPtr<ICommand> > CommandCollection::initializeCommands()
{
	HashMap<SharedPtr<ICommand> > tmp;

	tmp.insert("load", SharedPtr<ICommand>(new Load));
	tmp.insert("new", SharedPtr<ICommand>(new New));
	tmp.insert("save", SharedPtr<ICommand>(new Save));
	tmp.insert("len", SharedPtr<ICommand>(new Len));
	tmp.insert("dup", SharedPtr<ICommand>(new Dup));
	tmp.insert("rename", SharedPtr<ICommand>(new Rename));
	tmp.insert("del", SharedPtr<ICommand>(new Del));
	tmp.insert("help", SharedPtr<ICommand>(new Help));
	tmp.insert("find", SharedPtr<ICommand>(new Find));
	tmp.insert("pair", SharedPtr<ICommand>(new Pair));
	tmp.insert("quit", SharedPtr<ICommand>(new Quit));
	
	return tmp;
}

HashMap<SharedPtr<ICommand> > CommandCollection::commandMap = initializeCommands();


SharedPtr<ICommand> CommandCollection::getCommand(const std::string& command) const
{	
	try
	{
		return commandMap[command];
	}
	catch(const HashException &e)
	{
		throw InvalidCommand();
	}
}

std::vector<std::string> CommandCollection::getAllCommands() const
{
        return commandMap.keys();
}

