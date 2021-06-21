#include "ShowHelpPage.hpp"

#include <iostream>


void ShowHelpPage::execute()
{
    std::cout << "\nUsage:  COMMAND [PATH] [PACKAGE]\n\n"
              << "Commands:\n"
              << "  create 'package'          Creates root 'package'\n"
              << "  add    'path' 'package'   Adds new 'package' into 'path'\n"
              << "  remove 'path'             Removes all packages into 'path'\n"
              << "  print  [ path ]           Prints all packages recursively into 'path'\n\n"
              << "  help                      Shows this help page\n"
              << "  exit                      Exits from program\n\n";
}
