#include "AddPackage.hpp"

#include <iostream>


AddPackage::AddPackage(std::weak_ptr<Package> package, std::string&& path, std::string&& packageName)
    : _path(std::move(path)),
      _packageName(std::move(packageName)),
      _package(std::move(package))
{}

void AddPackage::execute()
{
    auto package = _package.lock();

    if(package && package->add(_path, _packageName) != Package::OperationResult::NO_ERROR)
    {
        std::cerr << "Error: Failed to add package: " << _packageName << std::endl;
    }
}
