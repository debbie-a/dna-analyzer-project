#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__

#include <string>

class ICommand
{

public:
	virtual std::string execute(char **argv) = 0;
};

#endif /* __ICOMMAND_H__*/
