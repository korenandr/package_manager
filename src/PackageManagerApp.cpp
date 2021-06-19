#include "PackageManagerApp.hpp"

#include <iostream>

namespace
{

void showHelpPage()
{
    std::cout << "Hello, from my package manager app!\n";
}

int readCommand()
{
    std::cout << "Input command:\n";

    // TODO: Parse and validate arguments
    // TODO: create and return command

    int cmd = 0;
    std::cin >> cmd;

    return cmd;
}

} //namespace


int PackageManagerApp::run(int argc, char** argv)
{
    showHelpPage();

    while(const auto cmd = readCommand())
    {
        if(cmd == 1)
        {
            _root.create("home");
            _root.add("project", "home/");
            _root.add("tesla", "home/project/");
            _root.add("build", "home/project/tesla/");
        }
        else if(cmd == 2)
        {
            std::string path("home/project");
            _root.remove(path);
        }
        else if(cmd == 3)
        {
            _root.print();
        }
    }

    return 0;
}
