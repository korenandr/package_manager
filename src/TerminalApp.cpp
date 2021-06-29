#include "TerminalApp.hpp"
#include "AppBuilder.hpp"

#include <cstdio>
#include <cxxopts.hpp>

namespace
{

const char* DEFAULT_GROUP = "";
const char* DEFAULT_LOG_CONFIG_FILE_PATH = "log.properties";
const char* DEFAULT_SERIALIZED_DATA_PATH = "input.json";


std::string createLogFilePath(const cxxopts::ParseResult& parseResult)
{
    if(parseResult.count("log") != 0)
    {
        const auto path = parseResult["log"].as<std::string>() + "/logs.txt";

        if(FILE* file = fopen(path.c_str(), "w"))
        {
            fclose(file);
            return path;
        }
        else
        {
            std::cerr << "Failed to open log file: " << path << '\n';
            std::cout << "Default path for log files will be /dev/null\n";
        }
    }

    return "/dev/null";
}

AppOptions readOptions(cxxopts::Options& options, int argc, char** argv)
{
    try
    {
        auto result = options.parse(argc, argv);

        if (result.count("help"))
        {
            std::cout << options.help({DEFAULT_GROUP}) << std::endl;
            exit(EXIT_SUCCESS);
        }

        const auto serializedDataPath = result["data"].as<std::string>();
        const auto logFileConfigPath  = result["log"].as<std::string>();

        return AppOptions{serializedDataPath, logFileConfigPath};
    }
    catch (const cxxopts::OptionException& exc)
    {
        std::cerr << "Failed to run app: " << exc.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

cxxopts::Options makeOptions(int argc, char** argv)
{
    cxxopts::Options options(argv[0], "\nWelcome to my package manager!\n");
    options.add_options(DEFAULT_GROUP)
            ("h,help", "Print help (this page)")
            ("l,log", "Path to a config file for a logger", cxxopts::value<std::string>()->default_value(DEFAULT_LOG_CONFIG_FILE_PATH))
            ("d,data", "Path to a file with serialized packages", cxxopts::value<std::string>()->default_value(DEFAULT_SERIALIZED_DATA_PATH));
    return options;
}

}

int TerminalApp::run(int argc, char** argv)
{
    cxxopts::Options options = makeOptions(argc, argv);

    const auto appOpts = readOptions(options, argc, argv);

    _appImpl = AppBuilder::createApp(appOpts);

    return _appImpl->run(argc, argv);
}
