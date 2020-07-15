#ifndef __COMMAND_COLLECTION_H__
#define __COMMAND_COLLECTION_H__

#include <string>
#include <map>
#include "load.h"
#include "save.h"
#include "new.h"
#include "quit.h"
#include "../Exceptions/invalid_command.h"
#include "icommand.h"

class CommandCollection
{

public:
	static ICommand* getCommand(const std::string& command);

private:
	static std::map<const std::string, ICommand*> commandMap;
};

inline ICommand* CommandCollection::getCommand(const std::string& command)
{
	if (!commandMap.count(command))
		throw InvalidCommand();

	return commandMap[command];
}

#endif /*__COMMAND_COLLECTION_H__*/
