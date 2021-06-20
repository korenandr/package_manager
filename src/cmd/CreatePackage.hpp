#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_CREATEPACKAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_CREATEPACKAGE_HPP 

#include "Command.hpp"
#include "../package/PackageController.hpp"

#include <memory>


class CreatePackage final : public Command
{
public:
    CreatePackage(std::weak_ptr<PackageController> packageController, std::string&& path);

    void execute() override;

private:
    std::string _path;

    std::weak_ptr<PackageController> _packageController;
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_CREATEPACKAGE_HPP
