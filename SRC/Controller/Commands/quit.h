#ifndef __QUIT_H__
#define __QUIT_H__

#include "icommand.h"

class Quit : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);

	/*virtual*/std::string getInfo();
};



#endif /*__QUIT_H__*/
