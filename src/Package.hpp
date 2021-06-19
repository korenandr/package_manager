#ifndef TESLASUIT_PACKAGE_MANAGER_PACKAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_PACKAGE_HPP

#include <string>
#include <map>
#include <utility>


class Package final
{
public:

    enum class OperationResult
    {
        NO_ERROR = 0,
        PATH_NOT_EXISTS,
    };

private:

    using PackageIt = std::map<std::string, Package>::iterator;

public:

    OperationResult create(const std::string& name);

    OperationResult add(const std::string& path, const std::string& name);

    OperationResult remove(std::string path);

    OperationResult print(const std::string& path = "") const;

private:

    std::pair<PackageIt, bool> find(std::string relativePath);

private:

    std::map<std::string, Package> _rootPackage;
};


#endif //TESLASUIT_PACKAGE_MANAGER_PACKAGE_HPP
