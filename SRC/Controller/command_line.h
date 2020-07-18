#ifndef __COMMAND_LINE_H__
#define __COMMAND_LINE_H__

#include "../Model/Read/iread.h"
#include "../Model/Write/iwrite.h"
#include "shared_pointer.h"
#include "igui.h"


class CommandLine : public IGUI
{

public:
	CommandLine(const SharedPtr<IRead>& reader, const SharedPtr<IWrite>& writer);
	
	/*virtual*/ void executeCommands();

private:
	SharedPtr<IRead> m_reader;
	SharedPtr<IWrite> m_writer;

};

inline CommandLine::CommandLine(const SharedPtr<IRead>& reader, const SharedPtr<IWrite>& writer):m_reader(reader),m_writer(writer)
{
}


#endif /*__COMMAND_LINE_H__*/
