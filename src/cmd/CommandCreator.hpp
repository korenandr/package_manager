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
            CREATE_PACKAGE,
            ADD_PACKAGE,
            REMOVE_PACKAGE,
            PRINT_PACKAGE,
            SHOW_HELP_PAGE,
            SHOW_ERROR_MESSAGE,
            EXIT,

            UNKNOWN
        };

        COMMAND_TYPE type;
        std::string path;
        std::string packageName;

        friend std::istream& operator>>(std::istream& is, COMMAND_TYPE& type);
    };

public:
    static std::unique_ptr<Command> create(const Arguments& arg, std::weak_ptr<Package> root);
};

#endif //TESLASUIT_PACKAGE_MANAGER_CMD_COMMANDCREATOR_HPP
