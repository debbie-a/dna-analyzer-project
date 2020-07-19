#include <sstream>
#include <cstring>
#include "command_line.h"
#include "Commands/invalid_command.h"
#include "Commands/invalid_arguments.h"
#include "Commands/command_collection.h"
#include "utils.h"

void CommandLine::executeCommands()
{
	bool flag = true;
	while(flag)
	{
		std::string input, output;
		input = m_reader->read();
		std::vector<std::string> vec = parseString(input);
		std::vector<std::string> params(vec.begin() + 1 , vec.end() - 1);

		try
		{
			output = (CommandCollection::getCommand(std::string(vec[0])))->execute(params, &flag);

			if(output != "")
				m_writer->write(output);
		}
		catch(InvalidCommand& e)
		{
			m_writer->write(e.what());
		}
		catch(InvalidArguments& e)
		{
			m_writer->write(e.what());
		}
		catch(std::runtime_error& e)
		{
			m_writer->write(e.what());
		}

	}
	
}

