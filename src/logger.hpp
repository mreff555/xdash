#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <loglevel.hpp>
#include <chrono>
#include <string>
#include <map>
#include <memory>
#include <cstdio>

namespace xdash
{
    class Config config();
    class Logger
    {
        public:
        Logger(std::shared_ptr<Config> config);

        virtual ~Logger();

        void log(LogLevelE lvl, const char *format, ...);

        LogLevelE getLogLevel() const;

        bool setLogLevel(const LogLevelE value);

        std::string getLogDir() const;

        bool setLogDir(const std::string value);

        std::string getLogFilePrefix() const;

        bool setLogFilePrefix(const std::string value);

        short getMaxLogHistory() const;

        bool setMaxLogHistory(const short value);

        std::string getTimeFormat() const;

        bool setTimeFormat(const std::string value);

        private:
        bool init();

        std::string getTimeNow() const;

        std::shared_ptr<Config> mConfig;
        LogLevelE logLevel;
        std::string logDir;
        std::string logFilePrefix;
        std::map<LogLevelE, std::string> logLevelMap;
        short maxLogHistory;
        FILE *logFd;
        std::string timeFormat;
    };
}

#endif /* LOGGER_HPP */
