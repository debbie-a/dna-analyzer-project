#ifndef __DNA_COLLECTION_H__
#define __DNA_COLLECTION_H__

#include <map>
#include <string>
#include "../../MyLibrary/HashMap/hash_map.h"
#include "dna_data.h"


class DNACollection
{

public:
	static void addDNA(SharedPtr<DNAData>);
	static SharedPtr<DNAData> getDNA(size_t);
	static SharedPtr<DNAData> getDNA(const std::string&);
	static void removeDNA(size_t);
	static void removeDNA(const std::string&);
	//static void setDNA();TODO implement this func

private:
	static HashMap<std::string> mapIdToName;
	static HashMap<SharedPtr<DNAData> > mapNameToDNAData;
};

#endif /* __DNA_COLLECTION_H__*/
