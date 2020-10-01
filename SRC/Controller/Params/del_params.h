#ifndef __DEL_PARAMS_H__
#define __DEL_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"


class DelParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;
        
};


bool DelParams::isNumParamsValid(size_t numParams) const
{
        return numParams == 1;
}

void DelParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");

        m_params.push_back(params[0]);
}

#endif /*__DEL_PARAMS_H__*/
