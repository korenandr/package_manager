#ifndef TESLASUIT_PACKAGE_MANAGER_TERMINALAPP_HPP
#define TESLASUIT_PACKAGE_MANAGER_TERMINALAPP_HPP

#include <memory>

#include "App.hpp"


class TerminalApp final : public App
{
public:
    int run(int argc, char** argv) override;

private:
    std::unique_ptr<App> _appImpl;
};

#endif //TESLASUIT_PACKAGE_MANAGER_TERMINALAPP_HPP
