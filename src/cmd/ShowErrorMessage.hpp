#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_SHOWERRORMESSAGE_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_SHOWERRORMESSAGE_HPP 

#include "Command.hpp"


class ShowErrorMessage final : public Command
{
public:
    void execute() override;
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_SHOWERRORMESSAGE_HPP
