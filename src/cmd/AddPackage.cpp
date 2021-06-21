#include "AddPackage.hpp"

#include <iostream>


AddPackage::AddPackage(std::weak_ptr<ns::PackageController> packageController, std::string&& path, std::string&& packageName)
    : _path(std::move(path)),
      _packageName(std::move(packageName)),
      _packageController(std::move(packageController))
{}

void AddPackage::execute()
{
    auto controller = _packageController.lock();

    if(controller && controller->add(_path, _packageName) != ns::Package::OperationResult::NO_ERROR)
    {
        std::cerr << "Error: Failed to add package: " << _packageName << std::endl;
    }
}
