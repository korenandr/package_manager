#include "InputCommandValidator.hpp"



std::string InputCommandValidator::message;


bool InputCommandValidator::isValid(const CommandCreator::Arguments& arg)
{
    // TODO: Add command arguments validation here!

    return true;
}

std::string InputCommandValidator::errorMessage()
{
    return message;
}
