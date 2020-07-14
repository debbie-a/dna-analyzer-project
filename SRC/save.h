#ifndef __SAVE_H__
#define __SAVE_H__


#include <iostream>
#include "icommand.h"

class Save : public ICommand
{

public:
	void execute();
};


inline void Save::execute()
{
	std::cout << "Hello from Save!" << std::endl;
}

#endif /*__SAVE_H__*/
