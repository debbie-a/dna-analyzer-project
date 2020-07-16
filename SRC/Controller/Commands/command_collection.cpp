#include "command_collection.h"


std::map<const std::string, SharedPtr<ICommand>> CommandCollection::commandMap = 
{
	{"load", SharedPtr<ICommand>(new Load)},
	{"new", SharedPtr<ICommand>(new New)},
	{"save", SharedPtr<ICommand>(new Save)},
	{"quit", SharedPtr<ICommand>(new Quit)}
};

