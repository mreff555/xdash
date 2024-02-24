#include <config.hpp>

using namespace xdash;
Config::Config()
: percentOverlayFill(DEFAULT_PERCENT_OVERLAY_FILL),
logLevel(DEFAULT_LOG_LEVEL),
logDir(DEFAULT_LOG_DIR),
logToStdout(DEFAULT_LOGTO_STDOUT),
logToStderr(DEFAULT_LOGTO_STDERR),
logFilePrefix(DEFAULT_LOG_FILE_PREFIX),
maxLogHistory(DEFAULT_MAX_LOG_HISTORY),
timeFormat(DEFAULT_TIME_FORMAT)
{}

unsigned int Config::getPercentOverlayFill() const
{
    return this->percentOverlayFill;
}

bool Config::setPercentOverlayFill(const unsigned int value)
{
    bool rtn = false;
    if(value > 0 && value <= 100)
    {
        this->percentOverlayFill = value;
        rtn = true;
    }
    return rtn;
}

LogLevelE Config::getLogLevel() const
{
    return this->logLevel;
}

bool Config::setLogLevel(const LogLevelE value)
{
    bool rtn = false;
    if(value >= 0 && value < LOG_LEVEL_MAX)
    {
        this->logLevel = value;
        rtn = true;
    }
    return rtn;
}

std::string Config::getLogDir() const
{
    return this->logDir;
}

bool Config::setLogDir(const std::string value)
{
    bool rtn = false;
    if(1 /*TODO: error handling*/)
    {
        this->logDir = value;
        rtn = true;
    }
    return rtn;
}

std::string Config::getLogFilePrefix() const
{
    return this->logFilePrefix;
}

bool Config::setLogFilePrefix(const std::string value)
{
    bool rtn = false;
    if(1 /*TODO: error handling*/)
    {
        this->logFilePrefix = value;
        rtn = true;
    }
    return rtn;
}

bool Config::getLogToStdout() const
{
    return this->logToStdout;
}

void Config::setLogToStdout(const bool value)
{
    this->logToStdout = value;
}

bool Config::getLogToStderr() const
{
    return this->logToStderr;
}

void Config::setLogToStderr(const bool value)
{
    this->logToStderr = value;
}

short Config::getMaxLogHistory() const
{
    return this->maxLogHistory;
}

bool Config::setMaxLogHistory(const short value)
{
    bool rtn = false;
    if(value > -2)
    {
        this->maxLogHistory = value;
        rtn = true;
    }
    return rtn;
}




std::string Config::getTimeFormat() const
{
    return this->timeFormat;
}

bool Config::setTimeFormat(const std::string value)
{
    bool rtn = false;
    if(1 /*TODO: error handling*/)
    {
        this->timeFormat = value;
        rtn = true;
    }
    return rtn;
}