#ifndef __CLI_H__
#define __CLI_H__

#include <string>
#include <sstream>
#include <cstring>
#include "./Commands/command_collection.h"
#include "./Read/iread.h"
#include "./Write/iwrite.h"

/*----------------------Auxiliary functions-------------------------------*/
inline static size_t getNumSpaces(const std::string& str)
{
	int count = 0; 
    	int length = str.length(); 
    	for (int i = 0; i < length; i++)
	{ 
		int c = str[i]; 
		if (isspace(c)) 
			count++; 
    	}
	return count;
}

inline static char** getStringSplitToArray(const std::string& s)
{
	char **arr;
	size_t i = 0;
	arr = new char*[getNumSpaces(s) + 2];
	std::istringstream ss(s); 
    	while (ss)
	{ 
        	std::string word; 
        	ss >> word;
		arr[i] = new char[word.length()];
		strcpy(arr[i], word.c_str());
		i++;
	}
	arr[i] = NULL;
	return arr;
   
}

inline static void freeAllocatedMemory(char **params)
{	
	size_t i = 0;
	while(*params[i])
	{
		delete params[i];
		i++;
	}
	delete params;
	params = NULL;
}
/*------------------------------------------------------------------------*/

class CLI
{

public:
	CLI(IRead *reader, IWrite *writer);

	void executeCommandLine();

private:
	IRead *m_reader;
	IWrite *m_writer;


};

inline CLI::CLI(IRead *reader, IWrite *writer):m_reader(reader),m_writer(writer)
{
}

inline void CLI::executeCommandLine()
{
	std::string input, output;
	input = m_reader->read();
	char **params = getStringSplitToArray(input);

	try
	{
		output = (CommandCollection::getCommand(std::string(params[0])))->execute(params + 1);
	}
	
	catch(InvalidCommand& e)
	{
		m_writer->write(e.what());
	}
	m_writer->write(output);

	freeAllocatedMemory(params);
	
}

#endif /*__CLI_H__*/
