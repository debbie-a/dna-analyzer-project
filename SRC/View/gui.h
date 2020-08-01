#ifndef __GUI_H__
#define __GUI_H__

#include "iview.h"

class GUI : public IView
{

public:

	/*virtual*/ void print(const std::string& stringToView);
};

#endif /*__GUI_H__*/
