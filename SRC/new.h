#ifndef __NEW_H__
#define __NEW_H__


#include <iostream>
#include "icommand.h"

class New : public ICommand
{
public:
	/*virtual*/void execute();
};


inline void New::execute()
{
	std::cout << "Hello from New!" << std::endl;
}


#endif /*__NEW_H__*/
