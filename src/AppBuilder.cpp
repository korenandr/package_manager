#include "AppBuilder.hpp"
#include "PackageManagerApp.hpp"



std::unique_ptr<App> AppBuilder::createApp(const AppOptions& options)
{
    // 1. Create logger
    // 2. Check for serialized file

    return std::make_unique<PackageManagerApp>();
}
