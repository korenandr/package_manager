#include "PrintPackage.hpp"

#include <iostream>


PrintPackage::PrintPackage(std::weak_ptr<ns::PackageController> packageController, std::string&& path)
    : _path(std::move(path)),
      _packageController(std::move(packageController))
{}

void PrintPackage::execute()
{
    auto controller = _packageController.lock();

    if(controller && controller->print(_path) != ns::Package::OperationResult::NO_ERROR)
    {
        std::cerr << "Error: Failed to print: " << _path << std::endl;
    }
}
