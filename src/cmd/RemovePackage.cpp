#include "RemovePackage.hpp"

#include <iostream>


RemovePackage::RemovePackage(std::weak_ptr<Package> package, std::string&& path)
    : _path(std::move(path)),
      _package(std::move(package))
{}

void RemovePackage::execute()
{
    auto package = _package.lock();

    if(package && package->remove(_path) != Package::OperationResult::NO_ERROR)
    {
        std::cerr << "Error: Failed to remove: " << _path << std::endl;
    }
}
