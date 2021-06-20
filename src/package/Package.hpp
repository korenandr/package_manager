#ifndef TESLASUIT_PACKAGE_MANAGER_PACKAGE_PACKAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_PACKAGE_PACKAGE_HPP

#include <string>
#include <map>


class Package
{
public:

    enum class OperationResult
    {
        NO_ERROR = 0,
        PATH_NOT_EXISTS,
        ALREADY_EXISTS
    };

private:

    using PackageIt = std::map<std::string, Package>::iterator;

public:

    explicit Package(std::string name);
    virtual ~Package() = default;

    /*
    Package(const Package&) = delete;
    Package& operator=(const Package&) = delete;

    Package(Package&&) = default;
    Package& operator=(Package&&) = default;
    */

public:

    OperationResult add(std::string path, const std::string& name);

    OperationResult remove(std::string path);

    OperationResult print(std::string path = "", std::size_t level = 0) const;

protected:

    std::string _name;

    std::map<std::string, Package> _rootPackages;
};


#endif //TESLASUIT_PACKAGE_MANAGER_PACKAGE_PACKAGE_HPP
