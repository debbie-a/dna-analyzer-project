#ifndef __CLI_H__
#define __CLI_H__

#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "Commands/command_collection.h"
#include "../Model/Read/iread.h"
#include "../Model/Write/iwrite.h"
#include "igui.h"

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

class CLI : public IGUI
{

public:
	CLI(SharedPtr<IRead> reader, SharedPtr<IWrite> writer);
	
	/*virtual*/ void executeCommand();

private:
	SharedPtr<IRead> m_reader;
	SharedPtr<IWrite> m_writer;

};

inline CLI::CLI(SharedPtr<IRead> reader, SharedPtr<IWrite> writer):m_reader(reader),m_writer(writer)
{
}

inline void CLI::executeCommand()
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

#endif /*__CLI_H__*/
