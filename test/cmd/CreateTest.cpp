#include <gtest/gtest.h>
#include "utils/InputCommandValidator.hpp"


using CA = CommandCreator::Arguments;
using CT = CA::COMMAND_TYPE;

TEST(CreateCommandTest, TEST_VALID_COMMAND)
{
    CA arg{ CT::CREATE_PACKAGE, "home" };

    ASSERT_EQ(arg.type, CT::CREATE_PACKAGE);
    ASSERT_EQ(arg.path, "home");
    ASSERT_TRUE(arg.packageName.empty());


    ASSERT_TRUE(InputCommandValidator::isValid(arg));
    ASSERT_EQ(InputCommandValidator::errorMessage(), "");
}

TEST(CreateCommandTest, TEST_TOO_MANY_ARGUMENTS)
{
    CA arg{ CT::CREATE_PACKAGE, "home", "package" };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}

TEST(CreateCommandTest, TEST_TOO_FEW_ARGUMENTS)
{
    CA arg{ CT::CREATE_PACKAGE };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}

TEST(CreateCommandTest, TEST_WRONG_PATH)
{
    CA arg{ CT::CREATE_PACKAGE, "ho/me" };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "/home";
    
    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "home/";
    
    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "home//media";

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}
