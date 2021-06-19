#ifndef TESLASUIT_PACKAGE_MANAGER_PACKAGEMANAGERAPP_HPP
#define TESLASUIT_PACKAGE_MANAGER_PACKAGEMANAGERAPP_HPP

#include <memory>

#include "App.hpp"
#include "Package.hpp"


class PackageManagerApp final : public App
{
public:
    int run(int argc, char** argv) override;

private:

    Package _root;
};

#endif //TESLASUIT_PACKAGE_MANAGER_PACKAGEMANAGERAPP_HPP
