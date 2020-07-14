#ifndef __CLI_H__
#define __CLI_H__

#include <string>
#include "command_factory.h"

class CLI
{

public:
	void executeCommand(const std::string& command);

};

inline void CLI::executeCommand(const std::string& command)
{
	//TODO: use CommandFactory map to create commands
	CommandFactory c;
	c.createCommand(command);
	
}

#endif /*__CLI_H__*/
