#include <gtest/gtest.h>
#include "utils/InputCommandValidator.hpp"


using CA = CommandCreator::Arguments;
using CT = CA::COMMAND_TYPE;

TEST(RemoveCommandTest, TEST_VALID_COMMAND)
{
    CA arg{ CT::REMOVE_PACKAGE, "home" };

    ASSERT_EQ(arg.type, CT::REMOVE_PACKAGE);
    ASSERT_EQ(arg.path, "home");
    ASSERT_TRUE(arg.packageName.empty());


    ASSERT_TRUE(InputCommandValidator::isValid(arg));
    ASSERT_EQ(InputCommandValidator::errorMessage(), "");


    arg.path = "home/media/device";

    ASSERT_TRUE(InputCommandValidator::isValid(arg));
    ASSERT_EQ(InputCommandValidator::errorMessage(), "");
}

TEST(RemoveCommandTest, TEST_TOO_MANY_ARGUMENTS)
{
    CA arg{ CT::REMOVE_PACKAGE, "home/media", "device" };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}

TEST(RemoveCommandTest, TEST_TOO_FEW_ARGUMENTS)
{
    CA arg{ CT::REMOVE_PACKAGE };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}

TEST(RemoveCommandTest, TEST_WRONG_PATH)
{
    CA arg{ CT::REMOVE_PACKAGE, "/home" };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "home/media/";
    
    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "home//media";
    
    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}
