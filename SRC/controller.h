#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <iostream>
#include <vector>
#include <map>
#include "cli.h"

/*----------------------Auxiliary functions-------------------------------*/
inline static void freeAllocatedMemory()
{
	delete CommandCollection::getCommand("load");
	delete CommandCollection::getCommand("new");
	delete CommandCollection::getCommand("save");
	delete CommandCollection::getCommand("quit");
}
/*------------------------------------------------------------------------*/


class Controller
{

public:
	Controller(IRead *reader, IWrite *writer);
	~Controller();

	void run() const;
	void shutDown() const;

private:
	
	CLI *m_cli;
};

inline Controller::Controller(IRead *reader, IWrite *writer):m_cli(new CLI(reader, writer))
{
}

inline Controller::~Controller()
{
	delete m_cli;
	m_cli = NULL;
	shutDown();
}

inline void Controller::run() const
{
	while(true)
	{
		m_cli->executeCommand();
	}
}

inline void Controller::shutDown() const
{
	freeAllocatedMemory();
	
	std::cout << "shutting down" << std::endl;
}

#endif /*__CONTROLLER_H__*/
