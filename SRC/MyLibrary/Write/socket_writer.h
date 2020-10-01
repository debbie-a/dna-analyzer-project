#ifndef __SOCKET_WRITER_H__
#define __SOCKET_WRITER_H__

#include "iwrite.h"

class SocketWriter : public IWrite
{

public:
	/*virtual*/void write(const std::string& str) const;
};

inline void SocketWriter::write(const std::string& str) const
{
	//TODO socket writing
}

#endif /*__SOCKET_WRITER_H__*/
