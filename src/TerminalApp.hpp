#ifndef PACKAGE_MANAGER_TERMINALAPP_HPP
#define PACKAGE_MANAGER_TERMINALAPP_HPP

#include <memory>

#include "App.hpp"


class TerminalApp final : public App
{
public:
    int run(int argc, char** argv) override;

private:
    std::unique_ptr<App> _appImpl;
};

#endif //PACKAGE_MANAGER_TERMINALAPP_HPP
