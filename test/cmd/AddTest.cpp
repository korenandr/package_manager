#include <gtest/gtest.h>
#include "utils/InputCommandValidator.hpp"


using CA = CommandCreator::Arguments;
using CT = CA::COMMAND_TYPE;

TEST(AddCommandTest, TEST_VALID_COMMAND)
{
    CA arg{ CT::ADD_PACKAGE, "home", "media" };

    ASSERT_EQ(arg.type, CT::ADD_PACKAGE);
    ASSERT_EQ(arg.path, "home");
    ASSERT_EQ(arg.packageName, "media");


    ASSERT_TRUE(InputCommandValidator::isValid(arg));
    ASSERT_EQ(InputCommandValidator::errorMessage(), "");
}

TEST(AddCommandTest, TEST_TOO_FEW_ARGUMENTS)
{
    CA arg{ CT::ADD_PACKAGE, "home" };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "";
    arg.packageName = "home";

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.path = "";
    arg.packageName = "";

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}

TEST(AddCommandTest, TEST_WRONG_PATH)
{
    CA arg{ CT::ADD_PACKAGE, "ho/me" };

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

TEST(AddCommandTest, TEST_WRONG_NAME)
{
    CA arg{ CT::ADD_PACKAGE, "home", "me/dia" };

    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.packageName = "/media";
    
    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");


    arg.packageName = "media/";
    
    ASSERT_FALSE(InputCommandValidator::isValid(arg));
    ASSERT_NE(InputCommandValidator::errorMessage(), "");
}
