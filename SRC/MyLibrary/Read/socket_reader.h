#ifndef __SOCKET_READER_H__
#define __SOCKET_READER_H__

#include "iread.h"

class SocketReader : public IRead
{

public:
	/*virtual*/std::string read() const;
};

inline std::string SocketReader::read() const
{
	//TODO socket reading
}

#endif /*__SOCKET_READER_H__*/
