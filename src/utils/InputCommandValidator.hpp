#ifndef PACKAGE_MANAGER_UTILS_INPUTCOMMANDVALIDATOR_HPP
#define PACKAGE_MANAGER_UTILS_INPUTCOMMANDVALIDATOR_HPP

#include "cmd/CommandCreator.hpp"

#include <string>


class InputCommandValidator final
{
public:
    
    static bool isValid(const CommandCreator::Arguments& arg);

    static std::string errorMessage();

private:

    static std::string message;
};


#endif //PACKAGE_MANAGER_UTILS_INPUTCOMMANDVALIDATOR_HPP
