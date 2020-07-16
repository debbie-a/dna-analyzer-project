#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <iostream>
#include <vector>
#include <map>
#include "cli.h"

class Controller
{

public:
	Controller(SharedPtr<IGUI> gui);

	void run();
	void shutDown() const;

private:
	SharedPtr<IGUI> m_gui;
};

inline Controller::Controller(SharedPtr<IGUI> gui):m_gui(gui)
{
}

inline void Controller::run()
{
	m_gui->executeCommand();
}

inline void Controller::shutDown() const
{
	std::cout << "shutting down" << std::endl;
}

#endif /*__CONTROLLER_H__*/
