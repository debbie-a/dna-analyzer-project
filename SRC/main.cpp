#include "Controller/controller.h"
#include "Model/Read/console_reader.h"
#include "Model/Write/console_writer.h"
#include "Model/Read/file_reader.h"
#include "Model/Write/file_writer.h"
#include "Controller/cli.h"


int main()
{
	SharedPtr<IRead> reader(new ConsoleReader);
	SharedPtr<IWrite> writer(new ConsoleWriter);
	SharedPtr<IGUI> gui(new CLI(reader, writer));

	Controller controller(gui);

	controller.run();
	controller.shutDown();

	return 0;
}
