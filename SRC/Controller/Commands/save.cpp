#include "save.h"
#include "../Utils/utils.h"
#include "../../Model/DNA/dna_collection.h"
#include "../../MyLibrary/Write/file_writer.h"


std::string Save::execute(SharedPtr<IParams> params)
{
        static const std::string PRODUCT_FOLDER = "Product/Internals/Saved/";

	// get the dnaSeq which needs to be saved
	SharedPtr<DNAData> dnaData = Utils::getDnaDataFromInput(params->m_params[0]);
	
	// writing to file
	SharedPtr<IWrite> writer(new FileWriter(PRODUCT_FOLDER + params->m_params[1]));
	writer->write((dnaData->getDNASeq())->getSequenceAsString());
	
	return "";
}

std::string Save::getInfo()
{
	return "\nSave DNA Sequences To File\nUser enters by name or ID a sequence to be saved to file.\nThe sequence is either saved in a file that user specified or in a default file name created according to name of sequence.\n";
}

