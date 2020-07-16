#ifndef __CONSOLE_READER_H__
#define __CONSOLE_READER_H__

#include <iostream>
#include "iread.h"

class ConsoleReader : public IRead
{

public:
	/*virtual*/std::string read();
};

inline std::string ConsoleReader::read()
{	
	std::cout << " > cmd >>> ";
	std::string input;
	getline(std::cin, input);

	return input;
}

#endif /*__CONSOLE_READER_H__*/
