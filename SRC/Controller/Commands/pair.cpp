#include "pair.h"
#include "../Utils/utils.h"


std::string Pair::execute(SharedPtr<IParams> params)
{
        // track the sequence to get its pair
	SharedPtr<DNAData> dnaData = Utils::getDnaDataFromInput(params->m_params[0]);

        std::string pairSeq = dnaData->getDNASeq()->pair().getSequenceAsString();

	SharedPtr<DNAData> pairedDnaData(new DNAData(pairSeq, params->m_params[1]));
	DNACollection::addDNA(pairedDnaData);

	return Utils::getOutput(pairedDnaData->getID(), params->m_params[1], pairSeq);
} 

std::string Pair::getInfo()
{
	return "\nGet the Paired Strand for a DNA Sequence\nBy typing pair and referring to a sequence get the second strand of the DNA molecule.\nA default name will be given to the paired strand if not specified otherwise.\n";
}

