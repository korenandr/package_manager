#include "CreatePackage.hpp"

#include <iostream>


CreatePackage::CreatePackage(std::weak_ptr<Package> package, std::string&& path)
    : _path(std::move(path)),
      _package(std::move(package))
{}

void CreatePackage::execute()
{
    auto package = _package.lock();

    if(package && package->create(_path) != Package::OperationResult::NO_ERROR)
    {
        std::cerr << "Error: Failed to create package: " << _path << std::endl;
    }
}
