#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_REMOVEPACKAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_REMOVEPACKAGE_HPP 

#include "Command.hpp"
#include "../Package.hpp"

#include <memory>


class RemovePackage final : public Command
{
public:
    explicit RemovePackage(std::weak_ptr<Package> package);

    void execute() override;

private:
    std::weak_ptr<Package> _package;
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_REMOVEPACKAGE_HPP
