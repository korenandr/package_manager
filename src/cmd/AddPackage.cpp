#include "AddPackage.hpp"

#include <iostream>


AddPackage::AddPackage(std::weak_ptr<Package> package)
    : _package(std::move(package))
{}

void AddPackage::execute()
{
    std::cout << "Add package executed!\n";
}
