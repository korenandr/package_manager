#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_PRINTPACKAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_PRINTPACKAGE_HPP 

#include "Command.hpp"
#include "../package/PackageController.hpp"

#include <memory>


class PrintPackage final : public Command
{
public:
    PrintPackage(std::weak_ptr<PackageController> packageController, std::string&& path);

    void execute() override;

private:
    std::string _path;

    std::weak_ptr<PackageController> _packageController;
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_PRINTPACKAGE_HPP
