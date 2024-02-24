#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <loglevel.hpp>
#include <chrono>
#include <string>
#include <map>
#include <memory>

namespace xdash
{
    class Config config();
    class Logger
    {
        public:
        Logger(std::shared_ptr<Config> config);

        virtual ~Logger() = default;

        void log(std::string value);

        LogLevelE getLogLevel() const;

        bool setLogLevel(const LogLevelE value);

        std::string getLogDir() const;

        bool setLogDir(const std::string value);

        std::string getLogFilePrefix() const;

        bool setLogFilePrefix(const std::string value);

        short getMaxLogHistory() const;

        bool setMaxLogHistory(const short value);

        private:
        auto getTimeNow() const;

        std::shared_ptr<Config> mConfig;
        LogLevelE logLevel;
        std::string logDir;
        std::string logFilePrefix;
        std::map<LogLevelE, std::string> logLevelMap;
        short maxLogHistory;
    };
}

#endif /* LOGGER_HPP */
