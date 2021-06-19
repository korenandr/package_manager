#include "RemovePackage.hpp"

#include <iostream>


RemovePackage::RemovePackage(std::weak_ptr<Package> package)
    : _package(std::move(package))
{}

void RemovePackage::execute()
{
    std::cout << "Remove package executed!\n";
}
