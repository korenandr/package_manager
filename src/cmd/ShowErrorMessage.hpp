#ifndef PACKAGE_MANAGER_CMD_SHOWERRORMESSAGE_HPP
#define PACKAGE_MANAGER_CMD_SHOWERRORMESSAGE_HPP 

#include "Command.hpp"


class ShowErrorMessage final : public Command
{
public:
    void execute() override;
};

#endif //PACKAGE_MANAGER_CMD_SHOWERRORMESSAGE_HPP
