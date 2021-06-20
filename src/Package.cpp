#include "Package.hpp"

#include <iostream>


namespace
{

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

std::string extractLastPackageName(std::string& path, char delimiter = '/')
{
    std::string packageName;
    size_t pos = path.find_last_of(delimiter);
    if(pos != std::string::npos) 
    {
        packageName = path.substr(pos+1, path.length());
        path.erase(pos, path.length());
    }

    return packageName;
}

}


Package::OperationResult Package::create(const std::string& name)
{
    _rootPackage[name];

    return OperationResult::NO_ERROR;
}

Package::OperationResult Package::add(const std::string& path, const std::string& name)
{
    auto it = find(path);

    if(!it.second)
    {
        std::cerr << "Not found path: " << path << std::endl;
        return OperationResult::PATH_NOT_EXISTS;
    }

    it.first->second._rootPackage[name];

    return OperationResult::NO_ERROR;
}

Package::OperationResult Package::remove(std::string path)
{
    const auto package = extractLastPackageName(path);
    auto it = find(path);

    if(!it.second)
    {
        std::cerr << "Not found path: " << path << std::endl;
        return OperationResult::PATH_NOT_EXISTS;
    }

    it.first->second._rootPackage.erase(package);
    return OperationResult::NO_ERROR;
}

Package::OperationResult Package::print(const std::string& path /*= ""*/) const
{
    std::cout << "Printed package: " << path << std::endl;
    return OperationResult::NO_ERROR;
}

std::pair<Package::PackageIt, bool> Package::find(std::string relativePath)
{    
    const auto package = extractFirstPackageName(relativePath);
    auto it = _rootPackage.find(package);

    if(it != _rootPackage.end())
    {
        if(relativePath.empty())
            return std::make_pair(it, true);

        return it->second.find(relativePath);
    }

    return std::make_pair(it, false);
}
