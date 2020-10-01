#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <vector>
#include "../../MyLibrary/shared_pointer.h"
#include "../../MyLibrary/Read/iread.h"
#include "../../MyLibrary/Write/iwrite.h"
#include "../../Model/DNA/dna_collection.h"


class Utils
{
public:
        static SharedPtr<DNAData> getDnaDataFromInput(const std::string&);
        static bool isId(const std::string&);
        static bool isName(const std::string&);
	static std::string getName(const std::string&);
	static size_t getId(const std::string&);
	static std::string getSuffixedName(const std::string&, const std::string& suffix = "_");
	static std::vector<std::string> parseString(const std::string&);
	static std::string getOutput(size_t id, const std::string&, const std::string&);
	static std::string replaceLongSeqWithEllipsis(const std::string&);
	static std::string getDefaultName(size_t*);
        static std::string getValidNewName(const std::string&);
	static bool confirmation(const SharedPtr<IRead>&, const SharedPtr<IWrite>&);
        static std::string getManipulationName(const std::string&);
        static bool isValidManipulationNewName(const std::string&);
        static bool isAutoGenerateName(const std::string&);
        static std::string getSubSeq(const std::string&);

        static const char NAME_SYMBOL = '@';
	static const char ID_SYMBOL = '#';

};

#endif /*__UTILS_H__*/
