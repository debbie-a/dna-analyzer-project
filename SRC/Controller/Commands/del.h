#ifndef __DEL_H__
#define __DEL_H__

#include "icommand.h"

class Del : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);

	/*virtual*/std::string getInfo();
};


#endif /*__DEL_H__*/
