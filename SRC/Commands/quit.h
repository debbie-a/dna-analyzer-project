#ifndef __QUIT_H__
#define __QUIT_H__

#include <cstdio>

class Quit : public ICommand
{

public:
	/*virtual*/std::string execute(char **argv);
};


inline std::string Quit::execute(char **argv)
{
	exit(1);
}

#endif /*__QUIT_H__*/
