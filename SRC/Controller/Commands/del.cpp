#include <sstream>
#include "del.h"
#include "../Utils/utils.h"
#include "../../Model/DNA/dna_collection.h"


std::string Del::execute(SharedPtr<IParams> params)
{
        // get the sequence to delete
	SharedPtr<DNAData> dnaData = Utils::getDnaDataFromInput(params->m_params[0]);

       m_writer->write("Do you really want to delete " + dnaData->getName() + ": " + dnaData->getDNASeq()->getSequenceAsString() + "?\n");

	if (Utils::confirmation(m_reader, m_writer))
	{
	        std::string output = Utils::getOutput(dnaData->getID(), dnaData->getName(), dnaData->getDNASeq()->getSequenceAsString());

		DNACollection::removeDNA(dnaData->getID());

                return "Deleted: " + output;
        }

	return "";
}

std::string Del::getInfo()
{
	return "\nDeletes DNA Sequences\nDelete a sequence by referring to it by its by name or ID, and the sequence is deleted from the system.\n";
}

