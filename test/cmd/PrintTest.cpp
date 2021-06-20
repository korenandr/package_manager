#include <gtest/gtest.h>
#include "utils/InputCommandValidator.hpp"


using CA = CommandCreator::Arguments;
using CT = CA::COMMAND_TYPE;

TEST(PrintCommandTest, TEST_VALID_COMMAND)
{
    CA arg{ CT::PRINT_PACKAGE, "home" };

    ASSERT_EQ(arg.type, CT::PRINT_PACKAGE);
    ASSERT_EQ(arg.path, "home");
    ASSERT_TRUE(arg.packageName.empty());


    ASSERT_TRUE(InputCommandValidator::isValid(arg));
    ASSERT_EQ(InputCommandValidator::errorMessage(), "");


    arg.path = "home/media/device";

    ASSERT_TRUE(InputCommandValidator::isValid(arg));
    ASSERT_EQ(InputCommandValidator::errorMessage(), "");
}

TEST(PrintCommandTest, TEST_TOO_MANY_ARGUMENTS)
{
    CA arg{ CT::PRINT_PACKAGE, "home/media", "device" };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}

TEST(CreateCommandTest, TEST_TOO_FEW_ARGUMENTS)
{
    CA arg{ CT::PRINT_PACKAGE };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}

TEST(CreateCommandTest, TEST_WRONG_PATH)
{
    CA arg{ CT::PRINT_PACKAGE, "/home" };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "home/media/";
    
    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "home//media";
    
    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}
