#ifndef __FIND_PARAMS_H__
#define __FIND_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"
#include "../Utils/utils.h"


class FindParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;
        
};


bool FindParams::isNumParamsValid(size_t numParams) const
{
        return numParams == 1 || numParams == 2;
}

void FindParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");

	m_params.push_back(params[0]);
        m_params.push_back(params[1]);
}

#endif /*__FIND_PARAMS_H__*/
