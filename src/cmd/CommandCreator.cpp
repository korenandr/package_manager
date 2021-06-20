#include "CommandCreator.hpp"

#include "ShowHelpPage.hpp"
#include "ShowErrorMessage.hpp"
#include "CreatePackage.hpp"
#include "AddPackage.hpp"
#include "RemovePackage.hpp"
#include "PrintPackage.hpp"


namespace 
{

using CT = CommandCreator::Arguments::COMMAND_TYPE;

CT to_commandType(const std::string& type)
{
    if(type == "create") { return CT::CREATE_PACKAGE; }
    if(type == "add")    { return CT::ADD_PACKAGE; }
    if(type == "remove") { return CT::REMOVE_PACKAGE; }
    if(type == "print")  { return CT::PRINT_PACKAGE; }
    if(type == "help")   { return CT::SHOW_HELP_PAGE; }
    if(type == "exit")   { return CT::EXIT; }

    return CT::UNKNOWN;
}

} //namespace


std::unique_ptr<Command> CommandCreator::create(Arguments&& arg, std::weak_ptr<PackageController> root)
{
    std::unique_ptr<Command> command;

    switch(arg.type)
    {
        case CT::CREATE_PACKAGE: command = std::make_unique<CreatePackage>(root, std::move(arg.path)); break;
        case CT::ADD_PACKAGE:    command = std::make_unique<AddPackage>(root, std::move(arg.path), std::move(arg.packageName)); break;
        case CT::REMOVE_PACKAGE: command = std::make_unique<RemovePackage>(root, std::move(arg.path)); break;
        case CT::PRINT_PACKAGE:  command = std::make_unique<PrintPackage>(root, std::move(arg.path)); break;
        case CT::SHOW_HELP_PAGE: command = std::make_unique<ShowHelpPage>(); break;
        case CT::SHOW_ERROR_MESSAGE: command = std::make_unique<ShowErrorMessage>(); break;
    }

    return command;
}


std::istream& operator>>(std::istream& is, CT& type)
{
    std::string stringType;
    is >> stringType;

    type = to_commandType(stringType);

    return is;
}
