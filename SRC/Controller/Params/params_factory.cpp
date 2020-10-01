#include "params_factory.h"
#include "../../MyLibrary/Exceptions/invalid_command.h"
#include "load_params.h"
#include "save_params.h"
#include "new_params.h"
#include "quit_params.h"
#include "len_params.h"
#include "dup_params.h"
#include "rename_params.h"
#include "help_params.h"
#include "find_params.h"
#include "del_params.h"
#include "pair_params.h"


HashMap<SharedPtr<IParams> > ParamsFactory::initializeParams()
{
	HashMap<SharedPtr<IParams> > tmp;

	tmp.insert("load", SharedPtr<IParams>(new LoadParams));
	tmp.insert("new", SharedPtr<IParams>(new NewParams));
	tmp.insert("save", SharedPtr<IParams>(new SaveParams));
	tmp.insert("len", SharedPtr<IParams>(new LenParams));
	tmp.insert("dup", SharedPtr<IParams>(new DupParams));
	tmp.insert("rename", SharedPtr<IParams>(new RenameParams));
	tmp.insert("del", SharedPtr<IParams>(new DelParams));
	tmp.insert("help", SharedPtr<IParams>(new HelpParams));
	tmp.insert("find", SharedPtr<IParams>(new FindParams));
	tmp.insert("pair", SharedPtr<IParams>(new PairParams));
	tmp.insert("quit", SharedPtr<IParams>(new QuitParams));
	
	return tmp;
}

HashMap<SharedPtr<IParams> > ParamsFactory::paramsMap = initializeParams();

SharedPtr<IParams> ParamsFactory::getParams(const std::string& command) const
{	
	try
	{
		return paramsMap[command];
	}
	catch(const HashException &e)
	{
		throw InvalidCommand();
	}
}
