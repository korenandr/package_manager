#ifndef PACKAGE_MANAGER_CMD_PRINTPACKAGE_HPP
#define PACKAGE_MANAGER_CMD_PRINTPACKAGE_HPP 

#include "Command.hpp"
#include "package/PackageController.hpp"

#include <memory>


class PrintPackage final : public Command
{
public:
    PrintPackage(std::weak_ptr<ns::PackageController> packageController, std::string&& path);

    void execute() override;

private:
    std::string _path;

    std::weak_ptr<ns::PackageController> _packageController;
};

#endif //PACKAGE_MANAGER_CMD_PRINTPACKAGE_HPP
