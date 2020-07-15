#include "controller.h"
#include "./Read/console_reader.h"
#include "./Write/console_writer.h"
#include "./Read/file_reader.h"
#include "./Write/file_writer.h"


IRead *reader = new ConsoleReader();
IWrite *writer = new ConsoleWriter();

Controller controller(reader, writer);

int main()
{
	controller.run();
	return 0;
}
