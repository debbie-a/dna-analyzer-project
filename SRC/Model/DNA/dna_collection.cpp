#include "dna_collection.h"
#include "invalid_dna_data.h"


std::map<size_t, std::string> DNACollection::mapIdToName;
std::map<const std::string, SharedPtr<DNAData>> DNACollection::mapNameToDNAData;

void DNACollection::addDNA(SharedPtr<DNAData> dnaData)
{
	mapIdToName[dnaData->getID()] = dnaData->getName();
	mapNameToDNAData[dnaData->getName()] = dnaData;
}

SharedPtr<DNAData> DNACollection::getDNA(size_t id)
{
	if (!mapIdToName.count(id))
		throw InvalidDNAData();

	return mapNameToDNAData[mapIdToName[id]];
}

SharedPtr<DNAData> DNACollection::getDNA(std::string name)
{
	if (!mapNameToDNAData.count(name))
		throw InvalidDNAData();

	return mapNameToDNAData[name];
}
/*
void DNACollection::setDNA(size_t id, DNAData* dnaData)
{
	
}*/

