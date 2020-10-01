#ifndef __HELP_H__
#define __HELP_H__

#include "icommand.h"

class Help : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams> params);

	/*virtual*/std::string getInfo();
};



#endif /*__HELP_H__*/
