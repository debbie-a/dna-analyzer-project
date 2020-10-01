#ifndef __LEN_PARAMS_H__
#define __LEN_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"


class LenParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;
        
};


bool LenParams::isNumParamsValid(size_t numParams) const
{
        return numParams == 1;
}

void LenParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");

        // get the sequence to find in it a sub-seq
	m_params.push_back(params[0]);
}

#endif /*__LEN_PARAMS_H__*/
