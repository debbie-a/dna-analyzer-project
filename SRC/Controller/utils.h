#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <vector>

std::vector<std::string> parseString(const std::string& s);
std::string getName(std::string str);
std::string getOutput(size_t id, std::string name, std::string seq);
std::string getNameFromFileName(std::string str);

#endif /*__UTILS_H__*/
