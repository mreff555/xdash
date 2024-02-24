#include <logger.hpp>
#include <config.hpp>
#include <filesystem>
#include <cassert>      // temporary to handle errors
#include <string>
#include <iomanip>
#include <sstream>

using namespace xdash;
Logger::Logger(std::shared_ptr<xdash::Config> config)
: mConfig(config),
logLevel(mConfig->getLogLevel()),
logDir(mConfig->getLogDir()),
logFilePrefix(mConfig->getLogFilePrefix()),
maxLogHistory(mConfig->getMaxLogHistory()),
timeFormat(mConfig->getTimeFormat())
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

    init();
}

void Logger::log(LogLevelE lvl, std::string value)
{
    if(lvl <= logLevel)
    {
        std::string logOut = "LOG::";
        logOut += this->logLevelMap[this->logLevel];
        logOut += "[";
        logOut += std::string(this->getTimeNow());
        logOut += "]: ";
        logOut += value;
        logFd.write(logOut.c_str(), logOut.size());

        //TODO: need to implement writing to stderr/stdout optionally.
    }

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

std::string Logger::getTimeFormat() const
{
    return this->timeFormat;
}

bool Logger::setTimeFormat(const std::string value)
{
    bool rtn = false;
    if(1 /*TODO: error handling*/)
    {
        this->timeFormat = value;
        rtn = true;
    }
    return rtn;
}

// Private
bool Logger::init()
{
    bool success = false;
    // create the log location if it does not exist
    std::filesystem::path fsPath(getLogDir());
    success = std::filesystem::create_directory(fsPath);

    // Increment all log history files by 1 so the new file
    // can be set to 0
    for(int i = 0; i < this->maxLogHistory; ++i)
    {
        std::filesystem::path filePath = fsPath;
        std::string filename = getLogFilePrefix();
        filename += std::to_string(i);
        filePath /= filename;
        //filePath.append(std::string(getLogFilePrefix() + std::to_string(i)));
        printf("%s\n", filePath.string().c_str());
        if(std::filesystem::exists(filePath))
        {
            std::filesystem::path newPath = fsPath;
            newPath.append(std::string(getLogFilePrefix() + std::to_string(i + 1)));
            std::filesystem::rename(fsPath, newPath);
        }
    }

    std::ios_base::openmode openmode = std::ios_base::out | std::ios_base::trunc;    
    logFd.open(std::string(this->logDir + this->logFilePrefix + std::to_string(0)), openmode);
    if(logFd.is_open())
    {
        success = true;
    }
    assert(success);
    return success;
}

std::string Logger::getTimeNow() const
{
    auto time = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(time);
    std::tm tm = *std::gmtime(&tt); //GMT (UTC)
    //std::tm tm = *std::localtime(&tt); //Locale time-zone, usually UTC by default.
    std::stringstream ss;
    ss << std::put_time( &tm, timeFormat.c_str() );
    return ss.str();
}
