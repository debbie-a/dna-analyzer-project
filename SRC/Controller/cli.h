#ifndef __CLI_H__
#define __CLI_H__

#include "../Model/Read/iread.h"
#include "../Model/Write/iwrite.h"
#include "../Model/shared_pointer.h"
#include "igui.h"


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


#endif /*__CLI_H__*/
