#ifndef __CACHE_H__
#define __CACHE_H__

#include <stack> 
#include <cstdio>

class Cache
{
public:
	static void updateSequenceIdentifier(size_t);
	static void updateLabelIdentifier(size_t);
	static size_t getSequenceIdentifier();
	static size_t getLabelIdentifier();
	static void removeSequenceIdentifier(size_t);
	static void removeLabelIdentifier(size_t);
	
private:
	static std::stack<size_t> sequenceIdentifier;
	static std::stack<size_t> labelIdentifier;
};

#endif /* __CACHE_H__*/
