#ifndef __COMMAND_FACTORY_H__
#define __COMMAND_FACTORY_H__

#include <string>
#include "load.h"
#include "save.h"
#include "new.h"
#include "quit.h"
#include "invalid_command.h"

class CommandFactory
{

public:
	void createCommand(const std::string& command);
};

inline void CommandFactory::createCommand(const std::string& command)
{
	if(command == "load")
	{
		Load load;
		load.execute();
	}
	else if(command == "save")
	{
		Save save;
		save.execute();
	}
	else if(command == "new")
	{
		New new_;
		new_.execute();
	}
	else if(command == "quit")
	{
		Quit quit;
		quit.execute();
	}
	else
		throw InvalidCommand();
}

#endif /*__COMMAND_FACTORY_H__*/
