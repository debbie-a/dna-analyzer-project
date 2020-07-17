#ifndef __SAVE_H__
#define __SAVE_H__

#include "icommand.h"

class Save : public ICommand
{

public:
	/*virtual*/std::string execute(const std::vector<std::string>& params, bool *flag);
};


#endif /*__SAVE_H__*/
