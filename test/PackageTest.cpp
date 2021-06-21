#include <gtest/gtest.h>
#include "package/PackageController.hpp"


using namespace ns;
using OR = Package::OperationResult;

TEST(PackageTest, TEST_CREATE)
{
    PackageController controller;

    ASSERT_EQ(controller.create("home"), OR::NO_ERROR);
    ASSERT_NE(controller.create("home"), OR::NO_ERROR);

    ASSERT_EQ(controller.create("media"), OR::NO_ERROR);
}

TEST(PackageTest, TEST_ADD)
{
    PackageController controller;

    ASSERT_EQ(controller.create("home"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("home", "project"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("home/project", "teslasuit"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("home/project/teslasuit", "build"), OR::NO_ERROR);


    ASSERT_EQ(controller.create("media"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("media", "device"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("media/device", "input"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("media/device/input", "headphones"), OR::NO_ERROR);


    ASSERT_EQ(controller.create("device"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("device", "headphones"), OR::NO_ERROR);
    ASSERT_NE(controller.add("device", "headphones"), OR::NO_ERROR);

    ASSERT_EQ(controller.add("device", "microphone"), OR::NO_ERROR);
    ASSERT_NE(controller.add("device", "microphone"), OR::NO_ERROR);
    

    ASSERT_NE(controller.add("device/not/created/folder", "microphone"), OR::NO_ERROR);
}

TEST(PackageTest, TEST_REMOVE)
{
    PackageController controller;

    ASSERT_EQ(controller.create("home"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("home", "project"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("home/project", "teslasuit"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("home/project/teslasuit", "build"), OR::NO_ERROR);

    ASSERT_EQ(controller.remove("home/project/teslasuit/build"), OR::NO_ERROR);
    ASSERT_NE(controller.remove("home/project/teslasuit/build"), OR::NO_ERROR);

    ASSERT_NE(controller.remove("home/not/created/folder"), OR::NO_ERROR);
}

TEST(PackageTest, TEST_PRINT)
{
    PackageController controller;

    ASSERT_EQ(controller.create("home"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("home", "project"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("home/project", "teslasuit"), OR::NO_ERROR);
    ASSERT_EQ(controller.add("home/project/teslasuit", "build"), OR::NO_ERROR);

    ASSERT_EQ(controller.print("home/project"), OR::NO_ERROR);
    ASSERT_EQ(controller.print("home/project/teslasuit"), OR::NO_ERROR);

    ASSERT_NE(controller.print("home/not/created/folder"), OR::NO_ERROR);
    ASSERT_NE(controller.print("home/another/not/created/folder"), OR::NO_ERROR);
}
