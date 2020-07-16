#ifndef __INVALID_COMMAND_H__
#define __INVALID_COMMAND_H__

#include <stdexcept>

class InvalidCommand : public std::runtime_error
{

public:
	InvalidCommand();

	/*virtual*/ const char* what() const throw();
};

inline InvalidCommand::InvalidCommand():std::runtime_error("")
{ 

}

inline const char* InvalidCommand::what() const throw()
{
        return "Invalid Command!!!";
}

#endif /*__INVALID_COMMAND_H__*/
