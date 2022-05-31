#ifndef PACKAGE_MANAGER_CMD_COMMAND_HPP
#define PACKAGE_MANAGER_CMD_COMMAND_HPP 


class Command
{
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
};

#endif //PACKAGE_MANAGER_CMD_COMMAND_HPP
