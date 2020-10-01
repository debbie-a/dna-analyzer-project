#ifndef __LOAD_PARAMS_H__
#define __LOAD_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"
#include "../Utils/utils.h"


class LoadParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;

        
        
};


bool LoadParams::isNumParamsValid(size_t numParams) const
{
        return numParams == 1 || numParams == 2;
}

void LoadParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");

        size_t i = params[0].find(".");
        // check that a file name was given
	if (i == std::string::npos)
	        throw InvalidArguments("invalid file name");
        
        m_params.push_back(params[0]);

        // a name for seq was given
	if(params.size() == 2)
	{
	        m_params.push_back(Utils::getName(params[1]));
	}
        // one parameter was sent. need to create name out of file name
	else
	{
		std::string tmp(params[0].begin(), params[0].begin() + i);

		// get name from file name. if name already exists - postfix name with serial number
		m_params.push_back(Utils::getSuffixedName(tmp));
	}
}

#endif /*__LOAD_PARAMS_H__*/
