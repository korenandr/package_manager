#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_COMMAND_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_COMMAND_HPP 


class Command
{
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_COMMAND_HPP
