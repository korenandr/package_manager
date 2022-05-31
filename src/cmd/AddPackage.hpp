#ifndef PACKAGE_MANAGER_CMD_ADDPACKAGE_HPP
#define PACKAGE_MANAGER_CMD_ADDPACKAGE_HPP 

#include "Command.hpp"
#include "../package/PackageController.hpp"

#include <memory>


class AddPackage final : public Command
{
public:
    AddPackage(std::weak_ptr<ns::PackageController> packageController, std::string&& path, std::string&& packageName);

    void execute() override;

private:
    std::string _path;
    std::string _packageName;

    std::weak_ptr<ns::PackageController> _packageController;
};

#endif //PACKAGE_MANAGER_CMD_ADDPACKAGE_HPP
