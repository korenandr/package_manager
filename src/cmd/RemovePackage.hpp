#ifndef PACKAGE_MANAGER_CMD_REMOVEPACKAGE_HPP
#define PACKAGE_MANAGER_CMD_REMOVEPACKAGE_HPP 

#include "Command.hpp"
#include "package/PackageController.hpp"

#include <memory>


class RemovePackage final : public Command
{
public:
    RemovePackage(std::weak_ptr<ns::PackageController> packageController, std::string&& path);

    void execute() override;

private:
    std::string _path;

    std::weak_ptr<ns::PackageController> _packageController;
};

#endif //PACKAGE_MANAGER_CMD_REMOVEPACKAGE_HPP
