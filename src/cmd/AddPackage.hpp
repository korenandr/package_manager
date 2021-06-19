#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_ADDPACKAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_ADDPACKAGE_HPP 

#include "Command.hpp"
#include "../Package.hpp"

#include <memory>


class AddPackage final : public Command
{
public:
    AddPackage(std::weak_ptr<Package> package, std::string&& path, std::string&& packageName);

    void execute() override;

private:
    std::string _path;
    std::string _packageName;

    std::weak_ptr<Package> _package;
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_ADDPACKAGE_HPP
