#include "Controller/controller.h"
#include "View/cli.h"


int main()
{
	SharedPtr<UI> ui(new CLI);
	
	Controller controller(ui);

	controller.run();
	controller.shutDown();
	
	return 0;
}
