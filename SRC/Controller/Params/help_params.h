#ifndef __HELP_PARAMS_H__
#define __HELP_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"


class HelpParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;
        
};


bool HelpParams::isNumParamsValid(size_t numParams) const
{
        return !numParams ||  numParams == 1;
}

void HelpParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");

        if (!params.empty())
                m_params.push_back(params[0]);
}

#endif /*__HELP_PARAMS_H__*/
