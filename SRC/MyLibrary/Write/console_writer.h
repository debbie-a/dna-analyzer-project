#ifndef __CONSOLE_WRITER_H__
#define __CONSOLE_WRITER_H__

#include <iostream>
#include "iwrite.h"

class ConsoleWriter : public IWrite
{

public:
	/*virtual*/void write(const std::string& str) const;
};

inline void ConsoleWriter::write(const std::string& str) const
{
	std::cout << str;
}

#endif /*__CONSOLE_WRITER_H__*/
