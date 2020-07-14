#ifndef __LOAD_H__
#define __LOAD_H__


#include <iostream>
#include "icommand.h"

class Load : public ICommand
{
public:
	/*virtual*/void execute();
};


inline void Load::execute()
{
	std::cout << "Hello from Load!" << std::endl;
}


#endif /*__LOAD_H__*/
