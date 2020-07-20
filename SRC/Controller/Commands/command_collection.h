#ifndef __COMMAND_COLLECTION_H__
#define __COMMAND_COLLECTION_H__

#include <string>
#include <map>
#include "load.h"
#include "save.h"
#include "new.h"
#include "quit.h"
#include "icommand.h"
#include "../shared_pointer.h"


class CommandCollection
{

public:

	static SharedPtr<ICommand> getCommand(const std::string& command);

private:
	
	static std::map<const std::string, SharedPtr<ICommand> > commandMap;
};



#endif /*__COMMAND_COLLECTION_H__*/
