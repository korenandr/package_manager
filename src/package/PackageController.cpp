#include "PackageController.hpp"

#include <iostream>


namespace
{
    const std::string DEFAULT_CONTROLLER_NAME = "/";
}


namespace ns
{

PackageController::PackageController()
    : Package(DEFAULT_CONTROLLER_NAME)
{}

PackageController::OperationResult PackageController::create(const std::string& name)
{
    const auto res = _rootPackages.insert({name, Package(name)});

    if(!res.second)
    {
        std::cerr << "Package " << name << " already exists!\n";
        return OperationResult::ALREADY_EXISTS;
    }

    return OperationResult::NO_ERROR;
}

}
