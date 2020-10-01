#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__

#include <string>
#include "../Params/iparams.h"
#include "../../MyLibrary/Read/console_reader.h"
#include "../../MyLibrary/Write/console_writer.h"
#include "../../MyLibrary/shared_pointer.h"


class ICommand
{

public:
	ICommand();
	ICommand(const SharedPtr<IRead>&, const SharedPtr<IWrite>&);

	virtual ~ICommand(){}

	virtual std::string execute(SharedPtr<IParams>) = 0;
	
	virtual std::string getInfo() = 0;


	SharedPtr<IRead> m_reader;
	SharedPtr<IWrite> m_writer;
	
};


inline ICommand::ICommand():m_reader(new ConsoleReader),m_writer(new ConsoleWriter)
{
}

inline ICommand::ICommand(const SharedPtr<IRead>& read, const SharedPtr<IWrite>& write):m_reader(read),m_writer(write)
{
}

#endif /* __ICOMMAND_H__*/
