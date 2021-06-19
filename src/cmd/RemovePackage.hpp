#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_REMOVEPACKAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_REMOVEPACKAGE_HPP 

#include "Command.hpp"
#include "../Package.hpp"

#include <memory>


class RemovePackage final : public Command
{
public:
    RemovePackage(std::weak_ptr<Package> package, std::string&& path);

    void execute() override;

private:
    std::string _path;

    std::weak_ptr<Package> _package;
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_REMOVEPACKAGE_HPP
