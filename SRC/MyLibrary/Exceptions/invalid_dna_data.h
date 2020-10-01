#ifndef __INVALID_DNA_DATA_H__
#define __INVALID_DNA_DATA_H__

#include <stdexcept>

class InvalidDNAData : public std::runtime_error
{

public:
	InvalidDNAData();

	/*virtual*/ const char* what() const throw();
};

inline InvalidDNAData::InvalidDNAData():std::runtime_error("")
{ 
}

inline const char* InvalidDNAData::what() const throw()
{
        return "invalid DNA data";
}

#endif /*__INVALID_DNA_DATA_H__*/
