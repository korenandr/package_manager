#include "PrintPackage.hpp"

#include <iostream>


PrintPackage::PrintPackage(std::weak_ptr<Package> package)
    : _package(std::move(package))
{}

void PrintPackage::execute()
{
    std::cout << "Print package executed!\n";
}
