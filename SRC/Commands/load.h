#ifndef __LOAD_H__
#define __LOAD_H__

#include "icommand.h"

class Load : public ICommand
{

public:
	/*virtual*/std::string execute(char **argv);
};


inline std::string Load::execute(char **argv)
{
	return "Hello from Load!";
}


#endif /*__LOAD_H__*/
