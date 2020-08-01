#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <iostream>
#include <vector>
#include <map>
#include "cli_logic.h"

class Controller
{

public:
	Controller(const SharedPtr<IViewLogic>& viewLogic);

	void run();
	void shutDown() const;

private:
	SharedPtr<IViewLogic> m_viewLogic;
};

inline Controller::Controller(const SharedPtr<IViewLogic>& viewLogic):m_viewLogic(viewLogic)
{
}

inline void Controller::run()
{
	m_viewLogic->executeCommands();
}

inline void Controller::shutDown() const
{
	std::cout << "shutting down" << std::endl;
}

#endif /*__CONTROLLER_H__*/
