#ifndef __PAIR_PARAMS_H__
#define __PAIR_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"
#include "../Utils/utils.h"


class PairParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;
        
};


bool PairParams::isNumParamsValid(size_t numParams) const
{
        return numParams == 3;
}

void PairParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");

       if (params[1] != ":")
		throw InvalidArguments("invalid syntax");

	m_params.push_back(params[0]);

	// take care of name for pair of sequence
        SharedPtr<DNAData> dnaData = Utils::getDnaDataFromInput(m_params[0]);

	m_params.push_back(Utils::isAutoGenerateName(params[2]) ? Utils::getSuffixedName(dnaData->getName(), "_p") : Utils::getManipulationName(params[2]));

}

#endif /*__PAIR_PARAMS_H__*/
