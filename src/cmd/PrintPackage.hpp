#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_PRINTPACKAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_PRINTPACKAGE_HPP 

#include "Command.hpp"
#include "../Package.hpp"

#include <memory>


class PrintPackage final : public Command
{
public:
    explicit PrintPackage(std::weak_ptr<Package> package);

    void execute() override;

private:
    std::weak_ptr<Package> _package;
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_PRINTPACKAGE_HPP
