#ifndef __NEW_H__
#define __NEW_H__

#include <sstream>
#include "icommand.h"

class New : public ICommand
{

public:
	/*virtual*/std::string execute(char **argv);
};


inline std::string New::execute(char **argv)
{
	std::stringstream s;
	int i = 0;
	while(*argv[i])
	{
		
		s << argv[i] << std::endl;;
		i++;
	}
	s << "Hello from New!";
	return s.str();
	
}


#endif /*__NEW_H__*/
