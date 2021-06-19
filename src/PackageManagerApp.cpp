#include "PackageManagerApp.hpp"

#include "cmd/CommandCreator.hpp"
#include "cmd/ShowHelpPage.hpp"

#include <iostream>
#include <memory>
 
#include <sstream>


namespace
{

CommandCreator::Arguments readArguments()
{
    std::string cmd;

    do {
        std::getline(std::cin, cmd);
    } 
    while(cmd.empty());

    std::stringstream ss(cmd);

    CommandCreator::Arguments arguments;
    ss >> arguments.type >> arguments.path >> arguments.packageName;

    // TODO: Add input validator!

    return arguments;
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
