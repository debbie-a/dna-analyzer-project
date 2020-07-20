#ifndef __IWRITE_H__
#define __IWRITE_H__

#include <string>

class IWrite
{

public:
	virtual ~IWrite(){}

	virtual  void write(const std::string&) = 0;
};

#endif /*__IWRITE_H__*/
