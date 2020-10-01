#ifndef __SAVE_H__
#define __SAVE_H__

#include "icommand.h"

class Save : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);
	
	/*virtual*/std::string getInfo();
};


#endif /*__SAVE_H__*/
