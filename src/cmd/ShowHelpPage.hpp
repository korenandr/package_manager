#ifndef PACKAGE_MANAGER_CMD_SHOWHELPPAGE_HPP
#define PACKAGE_MANAGER_CMD_SHOWHELPPAGE_HPP 

#include "Command.hpp"


class ShowHelpPage final : public Command
{
public:
    void execute() override;
};

#endif //PACKAGE_MANAGER_CMD_SHOWHELPPAGE_HPP
