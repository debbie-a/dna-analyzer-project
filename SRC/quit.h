#ifndef __QUIT_H__
#define __QUIT_H__

#include "quit_commands.h"

class Quit : public ICommand
{
public:
	/*virtual*/void execute();
};


inline void Quit::execute()
{
	throw QuitCommands();
}

#endif /*__QUIT_H__*/
