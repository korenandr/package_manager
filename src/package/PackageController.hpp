#ifndef TESLASUIT_PACKAGE_MANAGER_PACKAGE_PACKAGECONTROLLER_HPP
#define TESLASUIT_PACKAGE_MANAGER_PACKAGE_PACKAGECONTROLLER_HPP

#include "Package.hpp"


class PackageController final : public Package
{
public:
    PackageController();

    OperationResult create(const std::string& name);
};


#endif //TESLASUIT_PACKAGE_MANAGER_PACKAGE_PACKAGECONTROLLER_HPP
