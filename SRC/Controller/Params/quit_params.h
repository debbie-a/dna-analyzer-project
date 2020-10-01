#ifndef __QUIT_PARAMS_H__
#define __QUIT_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"


class QuitParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;
        
};


bool QuitParams::isNumParamsValid(size_t numParams) const
{
        return !numParams;
}

void QuitParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");
}

#endif /*__QUIT_PARAMS_H__*/
