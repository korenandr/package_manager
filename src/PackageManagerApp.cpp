#include "PackageManagerApp.hpp"

#include "cmd/CommandCreator.hpp"
#include "cmd/ShowHelpPage.hpp"

#include <iostream>
#include <memory>
 

namespace
{

CommandCreator::Arguments readArguments()
{
    std::cout << "Input command:\n";

    // TODO: Parse and validate arguments
    // TODO: create and return command

    int cmd = 0;
    std::cin >> cmd;

    return { static_cast<CommandCreator::Arguments::COMMAND_TYPE>(cmd), "", "" };
}

} //namespace


PackageManagerApp::PackageManagerApp()
    : _root(std::make_shared<Package>())
{}

int PackageManagerApp::run(int argc, char** argv)
{
    std::unique_ptr<Command> command = std::make_unique<ShowHelpPage>();

    while(command)
    {
        command->execute();

        command = CommandCreator::create(readArguments(), _root);
    }

    return 0;
}
