#include <gtest/gtest.h>
#include "Package.hpp"


using OR = Package::OperationResult;

TEST(PackageTest, TEST_CREATE)
{
    Package package;

    ASSERT_EQ(package.create("home"), OR::NO_ERROR);
    ASSERT_EQ(package.create("home"), OR::NO_ERROR);

    ASSERT_EQ(package.create("media"), OR::NO_ERROR);
}

TEST(PackageTest, TEST_ADD)
{
    Package package;

    ASSERT_EQ(package.create("home"), OR::NO_ERROR);
    ASSERT_EQ(package.add("home", "project"), OR::NO_ERROR);
    ASSERT_EQ(package.add("home/project", "teslasuit"), OR::NO_ERROR);
    ASSERT_EQ(package.add("home/project/teslasuit", "build"), OR::NO_ERROR);

    ASSERT_EQ(package.create("media"), OR::NO_ERROR);
    ASSERT_EQ(package.add("media", "device"), OR::NO_ERROR);
    ASSERT_EQ(package.add("media/device", "input"), OR::NO_ERROR);
    ASSERT_EQ(package.add("media/device/input", "headphones"), OR::NO_ERROR);
}

TEST(PackageTest, TEST_REMOVE)
{
    Package package;

    ASSERT_EQ(package.create("home"), OR::NO_ERROR);
    ASSERT_EQ(package.add("home", "project"), OR::NO_ERROR);
    ASSERT_EQ(package.add("home/project", "teslasuit"), OR::NO_ERROR);
    ASSERT_EQ(package.add("home/project/teslasuit", "build"), OR::NO_ERROR);

    ASSERT_EQ(package.remove("home/project/teslasuit"), OR::NO_ERROR);
}
