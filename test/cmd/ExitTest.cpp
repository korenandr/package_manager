#include <gtest/gtest.h>
#include "utils/InputCommandValidator.hpp"


using CA = CommandCreator::Arguments;
using CT = CA::COMMAND_TYPE;

TEST(ExitCommandTest, TEST_VALID_COMMAND)
{
    CA arg{ CT::EXIT };

    ASSERT_EQ(arg.type, CT::EXIT);
    ASSERT_TRUE(arg.path.empty());
    ASSERT_TRUE(arg.packageName.empty());


    ASSERT_TRUE(InputCommandValidator::isValid(arg));
    ASSERT_EQ(InputCommandValidator::errorMessage(), "");
}

TEST(ExitCommandTest, TEST_TOO_MANY_ARGUMENTS)
{
    CA arg{ CT::EXIT, "home" };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "";
    arg.packageName = "home";

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "home";
    arg.packageName = "media";

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}
