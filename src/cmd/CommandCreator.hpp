#ifndef TESLASUIT_PACKAGE_MANAGER_CMD_COMMANDCREATOR_HPP
#define TESLASUIT_PACKAGE_MANAGER_CMD_COMMANDCREATOR_HPP 

#include "Command.hpp"
#include "../Package.hpp"

#include <memory>


class CommandCreator final
{
public:
    struct Arguments final
    {
        enum class COMMAND_TYPE
        {
            SHOW_HELP_PAGE = 0,
            SHOW_ERROR_MESSAGE,
            CREATE_PACKAGE,
            ADD_PACKAGE,
            REMOVE_PACKAGE,
            PRINT_PACKAGE,
        };

        COMMAND_TYPE type;
        std::string path;
        std::string packageName;
    };

public:
    static std::unique_ptr<Command> create(const Arguments& arg, std::weak_ptr<Package> root);
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_COMMANDCREATOR_HPP
