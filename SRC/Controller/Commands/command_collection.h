#ifndef __COMMAND_COLLECTION_H__
#define __COMMAND_COLLECTION_H__

#include "../../MyLibrary/HashMap/hash_map.h"
#include "../../MyLibrary/shared_pointer.h"
#include "icommand.h"


class CommandCollection
{
public:
	SharedPtr<ICommand> getCommand(const std::string&) const;

	std::vector<std::string> getAllCommands() const;

private:
	static HashMap<SharedPtr<ICommand> > commandMap;

	static HashMap<SharedPtr<ICommand> > initializeCommands();
};


#endif /*__COMMAND_COLLECTION_H__*/
