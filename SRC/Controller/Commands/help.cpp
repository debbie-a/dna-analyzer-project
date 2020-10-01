#include <algorithm>
#include "help.h"
#include "command_collection.h"
#include "../../Model/DNA/dna_collection.h"
#include "../../MyLibrary/Exceptions/invalid_command.h"


std::string Help::execute(SharedPtr<IParams> params)
{
        SharedPtr<CommandCollection> commandCollection;

	if (!params->m_params.empty())
	{
		try
		{
			return commandCollection->getCommand(params->m_params[0])->getInfo();
		}
		catch (const InvalidCommand &e)
		{
			return "oops, it looks like you entered an invalid command";
		}
	}
	
	// case where no specific command given
	std::vector<std::string> allCommands = commandCollection->getAllCommands();
	std::sort(allCommands.begin(), allCommands.end());

	std::string output = "\nThe Available Commands For Dnanalyzer (from a-z):\n";

	for (size_t i = 0; i < allCommands.size(); i++)
	{
		output += allCommands[i] + "\n";
	}

	return output;
}

std::string Help::getInfo()
{
	return "\nGet Help To Understand Dnanalyzer System\nCan get information about a specific feature by specifying the command or alternatively get the list of all commands.\n";
}
