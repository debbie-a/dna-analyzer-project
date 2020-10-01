#ifndef __PARAMS_FACTORY_H__
#define __PARAMS_FACTORY_H__

#include "../../MyLibrary/HashMap/hash_map.h"
#include "../../MyLibrary/shared_pointer.h"
#include "iparams.h"


class ParamsFactory
{
public:
	SharedPtr<IParams> getParams(const std::string&) const;

private:
	static HashMap<SharedPtr<IParams> > paramsMap;

	static HashMap<SharedPtr<IParams> > initializeParams();
};


#endif /*__PARAMS_FACTORY_H__*/
