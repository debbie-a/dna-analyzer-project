#ifndef __NEW_PARAMS_H__
#define __NEW_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"
#include "../Utils/utils.h"


class NewParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;
        
};


bool NewParams::isNumParamsValid(size_t numParams) const
{
        return numParams == 1 || numParams == 2;
}

void NewParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");

        m_params.push_back(params[0]);

        // a name was given
        if (params.size() == 2)
	{
                m_params.push_back(Utils::getValidNewName(params[1]));
	}
}

#endif /*__NEW_PARAMS_H__*/
