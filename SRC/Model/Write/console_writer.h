#ifndef __CONSOLE_WRITER_H__
#define __CONSOLE_WRITER_H__

#include <iostream>
#include "iwrite.h"

class ConsoleWriter : public IWrite
{

public:
	/*virtual*/void write(const std::string& str);
};

inline void ConsoleWriter::write(const std::string& str)
{
	std::cout << str << std::endl;
}

#endif /*__CONSOLE_WRITER_H__*/
