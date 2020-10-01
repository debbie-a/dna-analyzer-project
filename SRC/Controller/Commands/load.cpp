#include <fstream>
#include <sstream>
#include "load.h"
#include "../Utils/utils.h"
#include "../../Model/DNA/dna_collection.h"
#include "../../MyLibrary/Read/file_reader.h"
#include "../../MyLibrary/Exceptions/invalid_dna_data.h"


std::string Load::execute(SharedPtr<IParams> params)
{
	std::string name;
	
	// reading from file
	SharedPtr<IRead> reader(new FileReader(params->m_params[0]));
	std::string seq = reader->read();

	std::string output;

	try
	{
		SharedPtr<DNAData> dnaData(new DNAData(seq, params->m_params[1]));
		DNACollection::addDNA(dnaData);

		output = Utils::getOutput(dnaData->getID(), params->m_params[1], seq);

	}
	catch(const InvalidNucleotide& e)
	{
		throw;
	}

	// if seq longer than 40 need to replace some with an ellipsis

	return seq.length() > 40 ? Utils::replaceLongSeqWithEllipsis(output) : output;
}

std::string Load::getInfo()
{
	return "\nLoads DNA Sequences from Files\nLoads from a file a dna sequence and and adds it to the system.\nThe sequence will get a default name if not specified otherwise.\n";
}

