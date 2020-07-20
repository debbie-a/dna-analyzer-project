#ifndef __DNA_COLLECTION_H__
#define __DNA_COLLECTION_H__

#include <map>
#include <string>
#include "dna_data.h"

class DNACollection
{

public:
	static void addDNA(SharedPtr<DNAData>);
	static SharedPtr<DNAData> getDNA(size_t id);
	static SharedPtr<DNAData> getDNA(std::string name);
	//static void setDNA();TODO implement this func

private:
	static std::map<size_t, std::string> mapIdToName;
	static std::map<const std::string, SharedPtr<DNAData> > mapNameToDNAData;
};
#endif /* __DNA_COLLECTION_H__*/
