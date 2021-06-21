#include "RemovePackage.hpp"

#include <iostream>


RemovePackage::RemovePackage(std::weak_ptr<ns::PackageController> packageController, std::string&& path)
    : _path(std::move(path)),
      _packageController(std::move(packageController))
{}

void RemovePackage::execute()
{
    auto controller = _packageController.lock();

    if(controller && controller->remove(_path) != ns::Package::OperationResult::NO_ERROR)
    {
        std::cerr << "Error: Failed to remove: " << _path << std::endl;
    }
}
