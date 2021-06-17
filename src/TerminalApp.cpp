#include "TerminalApp.hpp"
#include "AppBuilder.hpp"

#include <cstdio>
#include <cxxopts.hpp>

namespace
{

const char* DEFAULT_GROUP = "";
const char* DEFAULT_LOG_PATH = "";
const char* DEFAULT_SERIALIZED_DATA_PATH = "";


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

        const auto serializedDataPath = result.count("data") ? result["data"].as<std::string>() : DEFAULT_SERIALIZED_DATA_PATH;
        const auto logFilePath = result.count("log") ? result["log"].as<std::string>() : DEFAULT_LOG_PATH;

        return AppOptions{serializedDataPath, logFilePath};
    }
    catch (const cxxopts::OptionException& exc)
    {
        std::cerr << "Failed to run app: " << exc.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

cxxopts::Options makeOptions(int argc, char** argv)
{
    cxxopts::Options options(argv[0], "\nSome text\n");
    options.add_options(DEFAULT_GROUP)
            ("h,help", "Print help (this page)")
            ("l,log", "Path to a directory where to put a log file", cxxopts::value<std::string>())
            ("d,data", "Path to a file with serialized packages", cxxopts::value<std::string>());
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
