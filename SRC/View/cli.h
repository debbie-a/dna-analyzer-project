#ifndef __CLI_H__
#define __CLI_H__

#include "iview.h"

class CLI : public IView
{

public:

	/*virtual*/ void print(const std::string& stringToView);
};

#endif /*__CLI_H__*/
