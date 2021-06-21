#include "PackageManagerApp.hpp"

#include "cmd/CommandCreator.hpp"
#include "cmd/ShowHelpPage.hpp"
#include "utils/InputCommandValidator.hpp"

#include <algorithm>
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

    std::for_each(cmd.begin(), cmd.end(), [](char & c){
        c = ::tolower(c);
    });

    std::stringstream ss(cmd);

    CommandCreator::Arguments arguments;
    ss >> arguments.type >> arguments.path >> arguments.packageName;

    if(!InputCommandValidator::isValid(arguments))
    {
        arguments.type = CommandCreator::Arguments::COMMAND_TYPE::SHOW_ERROR_MESSAGE;
    }

    return arguments;
}

} //namespace


PackageManagerApp::PackageManagerApp(const std::string& serializedDataPath)
    : _root(std::make_shared<ns::PackageController>(serializedDataPath))
{
}

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
