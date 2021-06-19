#include "CommandCreator.hpp"

#include "ShowHelpPage.hpp"
#include "CreatePackage.hpp"
#include "AddPackage.hpp"
#include "RemovePackage.hpp"
#include "PrintPackage.hpp"



std::unique_ptr<Command> CommandCreator::create(const Arguments& arg, std::weak_ptr<Package> root)
{
    std::unique_ptr<Command> command;

    switch(arg.type)
    {
        case Arguments::COMMAND_TYPE::SHOW_HELP_PAGE: command = std::make_unique<ShowHelpPage>(); break;
        case Arguments::COMMAND_TYPE::CREATE_PACKAGE: command = std::make_unique<CreatePackage>(root); break;
        case Arguments::COMMAND_TYPE::ADD_PACKAGE:    command = std::make_unique<AddPackage>(root); break;
        case Arguments::COMMAND_TYPE::REMOVE_PACKAGE: command = std::make_unique<RemovePackage>(root); break;
        case Arguments::COMMAND_TYPE::PRINT_PACKAGE:  command = std::make_unique<PrintPackage>(root); break;
    }

    return command;
}
