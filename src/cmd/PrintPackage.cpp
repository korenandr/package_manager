#include "PrintPackage.hpp"

#include <iostream>


PrintPackage::PrintPackage(std::weak_ptr<Package> package, std::string&& path)
    : _path(std::move(path)),
      _package(std::move(package))
{}

void PrintPackage::execute()
{
    auto package = _package.lock();

    if(package && package->print(_path) != Package::OperationResult::NO_ERROR)
    {
        std::cerr << "Error: Failed to print: " << _path << std::endl;
    }
}
