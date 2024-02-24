#include <logger.hpp>
#include <config.hpp>
#include <filesystem>
#include <fstream>
#include <cassert>      // temporary to handle errors

using namespace xdash;
Logger::Logger(std::shared_ptr<xdash::Config> config)
: mConfig(config),
logLevel(mConfig->getLogLevel()),
logDir(mConfig->getLogDir()),
maxLogHistory(mConfig->getMaxLogHistory())
{
    logLevelMap = {
        {LOG_LEVEL_FATAL, "FATAL"},
        {LOG_LEVEL_WARNING, "WARNING"},
        {LOG_LEVEL_INFO, "INFO"},
        {LOG_LEVEL_LOGIC, "LOGIC"},
        {LOG_LEVEL_DEBUG, "DEBUG"},
        {LOG_LEVEL_TRACE, "TRACE"},
        {LOG_LEVEL_MAX, "MAX"}
    };

    // create the log location if it does not exist
    std::filesystem::path fsPath(getLogDir());
    bool success = std::filesystem::create_directory(fsPath);
    assert(success);

    // Increment all log history files by 1 so the new file
    // can be set to 0
    for(int i = 0; i < this->maxLogHistory; ++i)
    {
        std::filesystem::path filePath = fsPath;
        filePath.append(std::string(getLogFilePrefix() + std::to_string(i)));
        if(std::filesystem::exists(filePath))
        {
            std::filesystem::path newPath = fsPath;
            newPath.append(std::string(getLogFilePrefix() + std::to_string(i + 1)));
            std::filesystem::rename(fsPath, newPath);
        }
    }

}

void Logger::log(std::string value)
{
    // TODO
}

LogLevelE Logger::getLogLevel() const
{
    return this->logLevel;
}

bool Logger::setLogLevel(const LogLevelE value)
{
    bool rtn = false;
    if(value >= 0 && value < LOG_LEVEL_MAX)
    {
        this->logLevel = value;
        rtn = true;
    }
    return rtn;
}

std::string Logger::getLogDir() const
{
    return this->logDir;
}

bool Logger::setLogDir(const std::string value)
{
    bool rtn = false;
    if(1 /*TODO: add error handling*/)
    {
        this->logDir = value;
        rtn = true;
    }
    return rtn;
}


std::string Logger::getLogFilePrefix() const
{
    return this->logFilePrefix;
}

bool Logger::setLogFilePrefix(const std::string value)
{
    bool rtn = false;
    if(1 /*TODO: add error handling*/)
    {
        this->logFilePrefix = value;
        rtn = true;
    }
    return rtn;
}

short Logger::getMaxLogHistory() const
{
    return this->maxLogHistory;
}

bool Logger::setMaxLogHistory(const short value)
{
    bool rtn = false;
    if(value > -2)
    {
        this->maxLogHistory = value;
        rtn = true;
    }
    return rtn;
}

// Private
auto Logger::getTimeNow() const
{
    return std::chrono::system_clock::now();
}
