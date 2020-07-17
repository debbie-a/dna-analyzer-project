#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "cli.h"
#include "Commands/invalid_command.h"
#include "Commands/command_collection.h"


/*----------------------Auxiliary functions-------------------------------*/

inline static std::vector<std::string> parseString(const std::string& s)
{
	std::vector<std::string> vec;
	std::istringstream ss(s); 
    	while (ss)
	{ 
        	std::string word; 
        	ss >> word;
		vec.push_back(word);
	}

	return vec;
   
}

/*------------------------------------------------------------------------*/

void CLI::executeCommand()
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
		catch(std::runtime_error& e)
		{
			m_writer->write(e.what());
		}

	}
	
}
