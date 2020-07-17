#include "command_collection.h"
#include "invalid_command.h"


std::map<const std::string, SharedPtr<ICommand>> CommandCollection::commandMap = 
{
	{"load", SharedPtr<ICommand>(new Load)},
	{"new", SharedPtr<ICommand>(new New)},
	{"save", SharedPtr<ICommand>(new Save)},
	{"quit", SharedPtr<ICommand>(new Quit)}
};

SharedPtr<ICommand> CommandCollection::getCommand(const std::string& command)
{
	if (!commandMap.count(command))
		throw InvalidCommand();

	return commandMap[command];
}
