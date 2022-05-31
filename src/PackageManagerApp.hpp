#ifndef PACKAGE_MANAGER_PACKAGEMANAGERAPP_HPP
#define PACKAGE_MANAGER_PACKAGEMANAGERAPP_HPP

#include <memory>

#include "App.hpp"
#include "package/PackageController.hpp"


class PackageManagerApp final : public App
{
public:
    explicit PackageManagerApp(const std::string& serializedDataPath);

    int run(int argc, char** argv) override;

private:

    std::shared_ptr<ns::PackageController> _root;
};

#endif //PACKAGE_MANAGER_PACKAGEMANAGERAPP_HPP
