#include "AppBuilder.hpp"
#include "PackageManagerApp.hpp"

#include "./log/logger.hpp"


std::unique_ptr<App> AppBuilder::createApp(const AppOptions& options)
{
    initLog(options.logFileConfigPath);

    return std::make_unique<PackageManagerApp>(options.serializedDataPath);
}
