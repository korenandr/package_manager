#ifndef _LOGGER_H
#define _LOGGER_H

#include <log4cplus/logger.h>
#include <log4cplus/loglevel.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include <string>

void initLog(const std::string& confFile);

#endif /*_LOGGER_H*/
