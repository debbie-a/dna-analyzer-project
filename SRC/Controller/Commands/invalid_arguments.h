#ifndef __INVALID_ARGUMENTS_H__
#define __INVALID_ARGUMENTS_H__

#include <stdexcept>

class InvalidArguments : public std::runtime_error
{

public:
	InvalidArguments(const char *exception);

	/*virtual*/ const char* what() const throw();

private:
	const char *m_exception;
};

inline InvalidArguments::InvalidArguments(const char *exception):std::runtime_error(""),m_exception(exception)
{ 

}

inline const char* InvalidArguments::what() const throw()
{
        return m_exception;
}

#endif /*__INVALID_ARGUMENTS_H__*/
