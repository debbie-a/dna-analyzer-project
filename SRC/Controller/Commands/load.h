#ifndef __LOAD_H__
#define __LOAD_H__

#include "icommand.h"

class Load : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);

	/*virtual*/std::string getInfo();
};


#endif /*__LOAD_H__*/
