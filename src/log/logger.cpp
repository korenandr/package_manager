#include "logger.hpp"


void initLog(const std::string& confFile)
{
    log4cplus::Initializer initializer;

    log4cplus::BasicConfigurator config;
    config.configure();

    auto logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));

    LOG4CPLUS_TRACE(logger, "Logger initialization executed");
    LOG4CPLUS_DEBUG(logger, "This is a DEBUG message");
    LOG4CPLUS_INFO(logger, "This is a INFO message");
    LOG4CPLUS_WARN(logger, "This is a WARN message");
    LOG4CPLUS_ERROR(logger, "This is a ERROR message");
    LOG4CPLUS_FATAL(logger, "This is a FATAL message");
}
