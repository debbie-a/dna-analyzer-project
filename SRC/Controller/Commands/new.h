#ifndef __NEW_H__
#define __NEW_H__

#include "icommand.h"

class New : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);
	
	/*virtual*/std::string getInfo();
};


#endif /*__NEW_H__*/

