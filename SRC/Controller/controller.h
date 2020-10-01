#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Commands/command_collection.h"
#include "Params/params_factory.h"
#include "../View/ui.h"


class Controller
{
public:
	Controller(const SharedPtr<UI>&);
	
	std::string execCommand(const std::string&, std::vector<std::string>&) const;

	void run();
	void shutDown() const;

private:
	SharedPtr<UI> m_ui;
	SharedPtr<CommandCollection> m_commandCollection;
        SharedPtr<ParamsFactory> m_paramsFactory;
};


inline Controller::Controller(const SharedPtr<UI>& ui): m_ui(ui),m_commandCollection(new CommandCollection)
{
}

inline void Controller::run()
{
	Callback<Controller> callback = makeCallback(*this, &Controller::execCommand);
	m_ui->run(callback);
}

inline std::string Controller::execCommand(const std::string &command, std::vector<std::string>& params) const
{
        SharedPtr<IParams> commandParams = m_paramsFactory->getParams(command);

        try
        {
                // build params for specific command
                commandParams->buildParams(params);
                //execute command with params
	        std::string output = m_commandCollection->getCommand(command)->execute(commandParams);
                // clear params for that command
                commandParams->m_params.clear();

                return output;
        }
        catch (...)
        {
                // in case of exception must make sure to clear params
                commandParams->m_params.clear();
                throw;
        }
        
        
}

inline void Controller::shutDown() const
{
	m_ui->show("shutting down");
}

#endif /*__CONTROLLER_H__*/
