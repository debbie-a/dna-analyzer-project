#ifndef __IVIEW_H__
#define __IVIEW_H__

#include <string>

class IView
{

public:
	virtual ~IView(){}

	virtual void print(const std::string& stringToView) = 0;
};

#endif /*__IVIEW_H__*/
