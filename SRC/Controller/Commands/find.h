#ifndef __FIND_H__
#define __FIND_H__

#include "icommand.h"

class Find : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);
	
	/*virtual*/std::string getInfo();
};



#endif /*__FIND_H__*/
