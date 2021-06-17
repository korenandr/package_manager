#ifndef TESLASUIT_PACKAGE_MANAGER_APPBUILDER_HPP
#define TESLASUIT_PACKAGE_MANAGER_APPBUILDER_HPP 

#include <memory>

#include "App.hpp"

struct AppOptions
{
    std::string serializedDataPath;
    std::string logFilePath;
};

class AppBuilder
{
public:
    static std::unique_ptr<App> createApp(const AppOptions& options);
};


#endif //TESLASUIT_PACKAGE_MANAGER_APPBUILDER_HPP
