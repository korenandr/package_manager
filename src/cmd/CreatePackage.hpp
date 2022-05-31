#ifndef PACKAGE_MANAGER_CMD_CREATEPACKAGE_HPP
#define PACKAGE_MANAGER_CMD_CREATEPACKAGE_HPP 

#include "Command.hpp"
#include "package/PackageController.hpp"

#include <memory>


class CreatePackage final : public Command
{
public:
    CreatePackage(std::weak_ptr<ns::PackageController> packageController, std::string&& path);

    void execute() override;

private:
    std::string _path;

    std::weak_ptr<ns::PackageController> _packageController;
};

#endif //PACKAGE_MANAGER_CMD_CREATEPACKAGE_HPP
