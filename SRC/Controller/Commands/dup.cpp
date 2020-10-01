#include "dup.h"
#include "../Utils/utils.h"


std::string Dup::execute(SharedPtr<IParams> params)
{      
        SharedPtr<DNAData> dnaData = Utils::getDnaDataFromInput(params->m_params[0]);
        std::string seqToDup = dnaData->getDNASeq()->getSequenceAsString();
        std::string name = params->m_params.size() == 1 ? Utils::getSuffixedName(dnaData->getName()) : params->m_params[1];

	SharedPtr<DNAData> dupDNA(new DNAData(seqToDup, name));

	DNACollection::addDNA(dupDNA);

	return Utils::getOutput(dupDNA->getID(), name, seqToDup);
}

std::string Dup::getInfo()
{
	return "\nDuplicates DNA Sequences\nDuplicate an existing sequence by referring to it by its name or ID.\nA default name is given to the duplicated sequence if not specified otherwise.\n";

}

