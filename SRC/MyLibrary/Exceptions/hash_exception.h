#ifndef __HASH_EXCEPTION_H__
#define __HASH_EXCEPTION_H__

#include <stdexcept>

class HashException : public std::runtime_error
{
public:
	HashException(const std::string&);
};

inline HashException::HashException(const std::string& reason):std::runtime_error(reason)
{ 
}

#endif /*__HASH_EXCEPTION_H__*/
