#ifndef __INPUT_PROCESSOR_H__
#define __INPUT_PROCESSOR_H__

#include <string>
#include <vector>
#include <sstream>
#include "cache.h"


struct Args
{
        std::string command;
        std::vector<std::string> params;
};

class InputProcessor
{
public:
        Args processInput(const std::string&) const;

private:
        std::vector<std::string> parseInput(const std::string&) const;
	void touchUp(std::vector<std::string>&) const;

};

inline Args InputProcessor::processInput(const std::string& str) const
{
        Args args;
        std::vector<std::string> parsedInput = parseInput(str);
        std::vector<std::string> params(parsedInput.begin() + 1 , parsedInput.end() - 1);

        touchUp(params);

        args.command = parsedInput[0];
        args.params = params;

        return args;
}

inline std::vector<std::string> InputProcessor::parseInput(const std::string& str) const
{
	std::vector<std::string> vec;
	std::istringstream ss(str); 

    	while (ss)
	{ 
                std::string word; 
        	ss >> word;
		vec.push_back(word);
	}

	return vec; 
}

// for chache mechanizm
inline void InputProcessor::touchUp(std::vector<std::string>& vec) const
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == "##")
                {
                        std::stringstream ss;
                        ss << Cache::getSequenceIdentifier();
                        vec[i] = "#" + ss.str();
                }
		//CAL CACHING vec[i] == "_" ? ICommand::NAME_SYMBOL + Cache::getSequenceIdentifier() : vec[i];
	}
}


#endif /*__INPUT_PROCESSOR_H__*/
