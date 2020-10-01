#include <sstream>
#include "dna_collection.h"
#include "../../MyLibrary/Exceptions/invalid_dna_data.h"


HashMap<std::string> DNACollection::mapIdToName;
HashMap<SharedPtr<DNAData> > DNACollection::mapNameToDNAData;


void DNACollection::addDNA(SharedPtr<DNAData> dnaData)
{
	std::stringstream ss;
	ss << dnaData->getID();
	mapIdToName.insert(ss.str(), dnaData->getName());
	mapNameToDNAData.insert(dnaData->getName(), dnaData);
}

void DNACollection::removeDNA(size_t id)
{
	try
	{
		std::stringstream ss;
		ss << id;
		std::string name = mapIdToName[ss.str()];
		mapNameToDNAData.remove(name);
		mapIdToName.remove(ss.str());

	}
	catch(const HashException &e)
	{
		throw InvalidDNAData();
	}
	
}

void DNACollection::removeDNA(const std::string &name)
{
	try
	{
		std::stringstream ss;
		ss << (mapNameToDNAData[name]->getID());
		mapIdToName.remove(ss.str());	
		mapNameToDNAData.remove(name);
		
	}
	catch(const HashException &e)
	{
		throw InvalidDNAData();
	}
	
}

SharedPtr<DNAData> DNACollection::getDNA(size_t id)
{

	try
	{
		std::stringstream ss;
		ss << id;
		SharedPtr<DNAData> dnaData = mapNameToDNAData[mapIdToName[ss.str()]];

		return dnaData;
	}
	catch(const HashException &e)
	{
		throw InvalidDNAData();
	}
	
}

SharedPtr<DNAData> DNACollection::getDNA(const std::string &name)
{
	try
	{
		SharedPtr<DNAData> dnaData = mapNameToDNAData[name];

		return dnaData;
	}
	catch(const HashException &e)
	{
		throw InvalidDNAData();
	}

}
/*
void DNACollection::setDNA(size_t id, SharedPtr<DNAData> dnaData)
{
	
}*/

