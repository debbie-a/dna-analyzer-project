#ifndef __DUP_H__
#define __DUP_H__

#include "icommand.h"

class Dup : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);
	
	/*virtual*/std::string getInfo();
};



#endif /*__DUP_H__*/
