#include "Model/Read/console_reader.h"
#include "Model/Read/file_reader.h"
#include "Controller/controller.h"
#include "Controller/cli_logic.h"


int main()
{
	SharedPtr<IRead> reader(new ConsoleReader);
	SharedPtr<IView> viewer(new CLI);
	SharedPtr<IViewLogic> viewLogic(new CliLogic(viewer, reader));
	

	Controller controller(viewLogic);

	controller.run();
	controller.shutDown();
	
	return 0;
}
