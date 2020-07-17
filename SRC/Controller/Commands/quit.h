#ifndef __QUIT_H__
#define __QUIT_H__

#include "icommand.h"

class Quit : public ICommand
{

public:
	/*virtual*/std::string execute(const std::vector<std::string>& params, bool *flag);

};



#endif /*__QUIT_H__*/
