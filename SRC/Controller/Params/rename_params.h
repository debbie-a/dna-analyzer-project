#ifndef __RENAME_PARAMS_H__
#define __RENAME_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"
#include "../Utils/utils.h"


class RenameParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;
        
};


bool RenameParams::isNumParamsValid(size_t numParams) const
{
        return numParams == 2;
}

void RenameParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");

	m_params.push_back(params[0]);
        
        m_params.push_back(Utils::getName(params[1]));
}

#endif /*__RENAME_PARAMS_H__*/
