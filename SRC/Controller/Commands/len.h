#ifndef __LEN_H__
#define __LEN_H__

#include "icommand.h"

class Len : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);

	/*virtual*/std::string getInfo();
};



#endif /*__LEN_H__*/
