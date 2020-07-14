#ifndef __QUIT_COMMANDS_H__
#define __QUIT_COMMANDS_H__

#include <stdexcept>

class QuitCommands : public std::runtime_error
{

public:
	QuitCommands();

	/*virtual*/ const char* what() const throw();
};

inline QuitCommands::QuitCommands():std::runtime_error("")
{ 

}

inline const char* QuitCommands::what() const throw()
{
        return "quit";
}

#endif /*__QUIT_COMMANDS_H__*/
