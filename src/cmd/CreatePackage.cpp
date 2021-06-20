#include "CreatePackage.hpp"

#include <iostream>


CreatePackage::CreatePackage(std::weak_ptr<PackageController> packageController, std::string&& path)
    : _path(std::move(path)),
      _packageController(std::move(packageController))
{}

void CreatePackage::execute()
{
    auto controller = _packageController.lock();

    if(controller && controller->create(_path) != Package::OperationResult::NO_ERROR)
    {
        std::cerr << "Error: Failed to create package: " << _path << std::endl;
    }
}
