#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__

#include <string>
#include <vector>

class ICommand
{

public:
	virtual ~ICommand(){}

	virtual std::string execute(const std::vector<std::string>& params, bool *flag) = 0;
	
};

#endif /* __ICOMMAND_H__*/
