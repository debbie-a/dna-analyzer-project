#ifndef __PAIR_H__
#define __PAIR_H__

#include "icommand.h"

class Pair : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);
	
	/*virtual*/std::string getInfo();
};



#endif /*__PAIR_H__*/
