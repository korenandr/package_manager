#ifndef TESLASUIT_PACKAGE_MANAGER_PACKAGEMANAGERAPP_HPP
#define TESLASUIT_PACKAGE_MANAGER_PACKAGEMANAGERAPP_HPP

#include <memory>

#include "App.hpp"
#include "package/PackageController.hpp"


class PackageManagerApp final : public App
{
public:
    PackageManagerApp();

    int run(int argc, char** argv) override;

private:

    std::shared_ptr<ns::PackageController> _root;
};

#endif //TESLASUIT_PACKAGE_MANAGER_PACKAGEMANAGERAPP_HPP
