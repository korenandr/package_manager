#include "Package.hpp"

#include <iostream>


namespace
{

constexpr std::size_t LEVEL_INDENT_MULTIPLIER = 2;

std::string extractFirstPackageName(std::string& path, char delimiter = '/')
{
    std::string packageName;
    size_t pos = path.find(delimiter);
    if(pos != std::string::npos) 
    {
        packageName = path.substr(0, pos);
        path.erase(0, pos + 1);
    }
    else if(!path.empty())
    {
        packageName = path;
        path.clear();
    }

    return packageName;
}

}


namespace ns
{

Package::Package(std::string name)
    : _name(std::move(name))
{}

Package::OperationResult Package::add(std::string path, const std::string& name)
{
    if(path.empty())
    {
        const auto res = _rootPackages.insert({name, Package(name)});

        if(!res.second)
        {
            std::cerr << "Package " << name << " already exists!\n";
            return OperationResult::ALREADY_EXISTS;
        }

        return OperationResult::NO_ERROR;
    }

    const auto nextPackage = extractFirstPackageName(path);

    if(_rootPackages.count(nextPackage) == 0)
    {
        std::cerr << "Not found package: " << nextPackage << std::endl;
        return OperationResult::PATH_NOT_EXISTS;
    }

    return _rootPackages.at(nextPackage).add(path, name);
}

Package::OperationResult Package::remove(std::string path)
{
    if(path.empty())
    {
        _rootPackages.clear();
        return OperationResult::NO_ERROR;
    }

    const auto nextPackage = extractFirstPackageName(path);

    if(_rootPackages.count(nextPackage) == 0)
    {
        std::cerr << "Not found package: " << nextPackage << std::endl;
        return OperationResult::PATH_NOT_EXISTS;
    }

    if(path.empty())
    {
        _rootPackages.erase(nextPackage);
        return OperationResult::NO_ERROR;
    }

    return _rootPackages.at(nextPackage).remove(path);
}

Package::OperationResult Package::print(std::string path /*= "" */, std::size_t level /*= 0*/) const
{
    if(path.empty())
    {
        std::cout << std::string(LEVEL_INDENT_MULTIPLIER*level, ' ') << _name << std::endl;
        ++level;

        for(const auto& package : _rootPackages)
        {
            package.second.print("", level);
        }

        return OperationResult::NO_ERROR;
    }
 
    const auto nextPackage = extractFirstPackageName(path);

    if(_rootPackages.count(nextPackage) == 0)
    {
        std::cerr << "Not found package: " << nextPackage << std::endl;
        return OperationResult::PATH_NOT_EXISTS;
    }

    return _rootPackages.at(nextPackage).print(path);
}

}
