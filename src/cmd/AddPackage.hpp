#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_ADDPACKAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_ADDPACKAGE_HPP 

#include "Command.hpp"
#include "../package/PackageController.hpp"

#include <memory>


class AddPackage final : public Command
{
public:
    AddPackage(std::weak_ptr<PackageController> packageController, std::string&& path, std::string&& packageName);

    void execute() override;

private:
    std::string _path;
    std::string _packageName;

    std::weak_ptr<PackageController> _packageController;
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_ADDPACKAGE_HPP
