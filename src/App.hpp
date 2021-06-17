#ifndef TESLASUIT_PACKAGE_MANAGER_APP_HPP
#define TESLASUIT_PACKAGE_MANAGER_APP_HPP

class App
{
public:
    App() = default;

    App(const App&) = delete;

    App& operator=(const App&) = delete;

    App(App&&) noexcept = delete;

    App& operator=(App&&) noexcept = delete;

    virtual ~App() = default;

    virtual int run(int argc, char** argv) = 0;
};

#endif //TESLASUIT_PACKAGE_MANAGER_APP_HPP
