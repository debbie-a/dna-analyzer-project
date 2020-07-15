#include "command_collection.h"


std::map<const std::string, ICommand*> CommandCollection::commandMap = 
{
	{"load", new Load()},
	{"new", new New()},
	{"save", new Save()},
	{"quit", new Quit()}
};

