#include "AppBuilder.hpp"
#include "PackageManagerApp.hpp"



std::unique_ptr<App> AppBuilder::createApp(const AppOptions& options)
{
    // TODO: Create logger here

    return std::make_unique<PackageManagerApp>(options.serializedDataPath);
}
