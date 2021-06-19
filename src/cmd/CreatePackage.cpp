#include "CreatePackage.hpp"

#include <iostream>


CreatePackage::CreatePackage(std::weak_ptr<Package> package)
    : _package(std::move(package))
{}

void CreatePackage::execute()
{
    std::cout << "Create package executed!\n";
}
