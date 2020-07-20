#ifndef __IREAD_H__
#define __IREAD_H__

#include <string>

class IRead
{

public:
	virtual ~IRead(){}

	virtual std::string read() = 0;
};

#endif /*__IREAD_H__*/
