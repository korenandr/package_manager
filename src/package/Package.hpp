#ifndef PACKAGE_MANAGER_PACKAGE_PACKAGE_HPP
#define PACKAGE_MANAGER_PACKAGE_PACKAGE_HPP

#include <string>
#include <map>


#include "nlohmann/json.hpp"


namespace ns
{

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

    using Container = std::map<std::string, Package>;
    using PackageIt = Container::iterator;

public:

    Package() = default;

    explicit Package(std::string name);
    virtual ~Package() = default;

    Package(const Package&) = delete;
    Package& operator=(const Package&) = delete;

    Package(Package&&) = default;
    Package& operator=(Package&&) = default;

    friend bool operator==(const Package& lhs, const Package& rhs);
    friend bool operator!=(const Package& lhs, const Package& rhs);

public:

    OperationResult add(std::string path, const std::string& name);

    OperationResult remove(std::string path);

    OperationResult print(std::string path = "", std::size_t level = 0) const;

protected:

    std::string _name;

    Container _rootPackages;

public:

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Package, _name, _rootPackages)
};

}


#endif //PACKAGE_MANAGER_PACKAGE_PACKAGE_HPP
