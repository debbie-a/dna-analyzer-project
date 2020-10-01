#ifndef __SAVE_PARAMS_H__
#define __SAVE_PARAMS_H__

#include "iparams.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"
#include "../Utils/utils.h"
#include "../../Model/DNA/dna_collection.h"


class SaveParams : public IParams
{
public:
        /*virtual*/ void buildParams(const std::vector<std::string>&);

private:
        /*virtual*/ bool isNumParamsValid(size_t) const;
        
};


bool SaveParams::isNumParamsValid(size_t numParams) const
{
        return numParams == 1;
}

void SaveParams::buildParams(const std::vector<std::string>& params)
{
        if (!isNumParamsValid(params.size()))
		throw InvalidArguments("invalid number of arguments");

	m_params.push_back(params[0]);
        
        SharedPtr<DNAData> dnaData = Utils::getDnaDataFromInput(params[0]);

        // if one parameter was sent. need to create file name out of seq name
	m_params.push_back(params.size() == 1 ? dnaData->getName() + ".rawdna" : params[1]);
}

#endif /*__SAVE_PARAMS_H__*/
