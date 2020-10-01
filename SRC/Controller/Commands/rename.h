#ifndef __RENAME_H__
#define __RENAME_H__

#include "icommand.h"

class Rename : public ICommand
{

public:
	/*virtual*/std::string execute(SharedPtr<IParams>);

	/*virtual*/std::string getInfo();
};



#endif /*__RENAME_H__*/
