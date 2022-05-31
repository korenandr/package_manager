#ifndef PACKAGE_MANAGER_APPBUILDER_HPP
#define PACKAGE_MANAGER_APPBUILDER_HPP 

#include <memory>

#include "App.hpp"

struct AppOptions
{
    std::string serializedDataPath;
    std::string logFileConfigPath;
};

class AppBuilder
{
public:
    static std::unique_ptr<App> createApp(const AppOptions& options);
};


#endif //PACKAGE_MANAGER_APPBUILDER_HPP
