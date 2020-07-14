#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <iostream>
#include "cli.h"

class Controller
{

public:
	void run();
	void shutDown();

private:
	
	CLI *cli;
	//IWriter *iwriter;
	//IReader *ireader;
};
 

inline void Controller::run()
{
	while(true)
	{
		std::string inputCommand;
		std::cout << "enter command:" << std::endl;
		std::cin >> inputCommand;
		try
		{
			cli->executeCommand(inputCommand);
		}
		catch(QuitCommands& e)
		{
			break;
		}
		catch(InvalidCommand& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

inline void Controller::shutDown()
{
	std::cout << "shutting down" << std::endl;
}

#endif /*__CONTROLLER_H__*/
