#include "cache.h"
#include "../MyLibrary/Exceptions/invalid_arguments.h"


std::stack<size_t> Cache::sequenceIdentifier;
std::stack<size_t> Cache::labelIdentifier;


void Cache::updateSequenceIdentifier(size_t id)
{
	if (sequenceIdentifier.empty() || sequenceIdentifier.top() != id)
		sequenceIdentifier.push(id);
}

void Cache::updateLabelIdentifier(size_t id)
{
	if (labelIdentifier.empty() || labelIdentifier.top() != id)
		labelIdentifier.push(id);
}

size_t Cache::getSequenceIdentifier() 
{
	if (!sequenceIdentifier.empty())
		return sequenceIdentifier.top();
	
	throw InvalidArguments("invalid reference to ##");
}

size_t Cache::getLabelIdentifier() 
{
	if (!labelIdentifier.empty())
		return labelIdentifier.top();
	
	throw InvalidArguments("invalid reference to ##");
}

void Cache::removeSequenceIdentifier(size_t id) 
{
	std::stack<size_t> tmpStack;
	size_t tmpId;

	// must remove all occurrences of this name from stack
	while (!sequenceIdentifier.empty())
	{
		tmpId = sequenceIdentifier.top(); 
		if (tmpId != id)
		{
			tmpStack.push(tmpId);
		}
		sequenceIdentifier.pop(); 
	}
	sequenceIdentifier = tmpStack;
}

void Cache::removeLabelIdentifier(size_t id) 
{
	std::stack<size_t> tmpStack;
	size_t tmpId;

	// must remove all occurrences of this name from stack
	while (!labelIdentifier.empty())
	{
		tmpId = sequenceIdentifier.top(); 
		if (tmpId != id)
		{
			tmpStack.push(tmpId);
		}
		labelIdentifier.pop(); 
	}
	labelIdentifier = tmpStack;
}
