#include "ShowErrorMessage.hpp"

#include "../utils/InputCommandValidator.hpp"

#include <iostream>


void ShowErrorMessage::execute()
{
    std::cout << InputCommandValidator::errorMessage() << std::endl;
}
