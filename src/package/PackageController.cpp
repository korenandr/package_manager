#include "PackageController.hpp"

#include "nlohmann/json.hpp"

#include <fstream>
#include <iostream>


namespace
{
    const std::string DEFAULT_CONTROLLER_NAME = "/";
}


namespace ns
{

PackageController::PackageController(const std::string& serializedDataPath)
    : Package(DEFAULT_CONTROLLER_NAME),
      _serializedDataPath(serializedDataPath)
{
    deserialize();
}

PackageController::~PackageController()
{
    serialize();
}

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

void PackageController::serialize() const
{
    if(_serializedDataPath.empty())
        return;

    nlohmann::json json = _rootPackages;

    std::ofstream of(_serializedDataPath);

    of << json;
}

void PackageController::deserialize()
{
    if(_serializedDataPath.empty())
        return;

    std::ifstream data(_serializedDataPath);

    nlohmann::json json;

    try {

        data >> json;

        _rootPackages = json.get<std::map<std::string, ns::Package>>();
    }
    catch(...)
    {
        _rootPackages.clear();

        std::cerr << "Error: Cannot parse serialized data file: " << _serializedDataPath << std::endl;
    }
}

}
