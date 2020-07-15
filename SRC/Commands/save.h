#ifndef __SAVE_H__
#define __SAVE_H__

#include "icommand.h"

class Save : public ICommand
{

public:
	/*virtual*/std::string execute(char **argv);
};


inline std::string Save::execute(char **argv)
{
	return "Hello from Save!";
}

#endif /*__SAVE_H__*/
