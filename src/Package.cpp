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
    const auto res = _rootPackage.insert({name, Package()});

    if(!res.second)
    {
        std::cerr << "Couldnt create a new package: " << name << std::endl;
        return OperationResult::ALREADY_EXISTS;
    }

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

    const auto res = it.first->second._rootPackage.insert({name, Package()});

    if(!res.second)
    {
        std::cerr << "Package " << path << "/" << name << " already exists!\n";
        return OperationResult::ALREADY_EXISTS;
    }

    return OperationResult::NO_ERROR;
}

Package::OperationResult Package::remove(std::string path)
{
    const auto packageName = extractLastPackageName(path);
    auto it = find(path);

    if(!it.second)
    {
        std::cerr << "Not found path: " << path << std::endl;
        return OperationResult::PATH_NOT_EXISTS;
    }

    auto& package = it.first->second._rootPackage;

    if(package.count(packageName) == 0)
    {
        std::cerr << "Not found package: " << packageName << std::endl;
        return OperationResult::PATH_NOT_EXISTS;
    }

    package.erase(packageName);
    return OperationResult::NO_ERROR;
}

Package::OperationResult Package::print(const std::string& path /*= ""*/)
{
    if(path.empty())
    {
        innerPrint();
        return OperationResult::NO_ERROR;
    }
 
    auto it = find(path);

    if(!it.second)
    {
        std::cerr << "Not found path: " << path << std::endl;
        return OperationResult::PATH_NOT_EXISTS;
    }

    std::cout << std::endl << it.first->first << std::endl;

    it.first->second.innerPrint();

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

void Package::innerPrint(std::size_t level /*= 0*/)
{
    ++level;

    for(auto it = _rootPackage.begin(); it != _rootPackage.end(); ++it)
    {
        std::cout << std::string(LEVEL_INDENT_MULTIPLIER*level, ' ') << it->first << std::endl;

        it->second.innerPrint(level);
    }
}
