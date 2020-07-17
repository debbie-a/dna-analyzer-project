#ifndef __LOAD_H__
#define __LOAD_H__

#include "icommand.h"

class Load : public ICommand
{

public:
	/*virtual*/std::string execute(const std::vector<std::string>& params, bool *flag);
};



#endif /*__LOAD_H__*/
