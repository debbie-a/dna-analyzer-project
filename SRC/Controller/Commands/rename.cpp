#include "rename.h"
#include "../Utils/utils.h"
#include "../../Model/DNA/dna_collection.h"


std::string Rename::execute(SharedPtr<IParams> params)
{
	SharedPtr<DNAData> dnaData = Utils::getDnaDataFromInput(params->m_params[0]);
       
        SharedPtr<DNAData> renamedDnaData(new DNAData(dnaData->getDNASeq()->getSequenceAsString(), params->m_params[1], dnaData->getID()));
        DNACollection::removeDNA(dnaData->getID());
        DNACollection::addDNA(renamedDnaData);

	return "";
}

std::string Rename::getInfo()
{
	return "\nRenames DNA Sequences\nRenames the specified sequence to the new name that is given.\n";
}
