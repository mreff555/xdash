#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <loglevel.hpp>
#include <string>

// These hard coded values represent the REAL default values if
// a config file is not present.
constexpr unsigned short DEFAULT_PERCENT_OVERLAY_FILL = 80;
constexpr xdash::LogLevelE DEFAULT_LOG_LEVEL = xdash::LOG_LEVEL_INFO;
constexpr char* DEFAULT_LOG_DIR = "./log";
constexpr char* DEFAULT_LOG_FILE_PREFIX = "xdash_log_";
constexpr bool DEFAULT_LOGTO_STDOUT = false;
constexpr bool DEFAULT_LOGTO_STDERR = false;
constexpr short DEFAULT_MAX_LOG_HISTORY = 5;   
constexpr char* DEFAULT_TIME_FORMAT = "UTC: %Y-%m-%d %H:%M:%S";
constexpr char* DEFAULT_DESKTOP_SEARCH_PATH = "/usr/share/applications:/usr/local/share/applications";

namespace xdash
{
    class Config
    {
        public:
        Config();

        virtual ~Config() = default;

        unsigned int getPercentOverlayFill() const;

        bool setPercentOverlayFill(const unsigned int value);

        LogLevelE getLogLevel() const;

        bool setLogLevel(const LogLevelE value);

        std::string getLogDir() const;

        bool setLogDir(const std::string value);

        std::string getLogFilePrefix() const;

        bool setLogFilePrefix(const std::string value);

        bool getLogToStdout() const;

        void setLogToStdout(const bool value);

        bool getLogToStderr() const;

        void setLogToStderr(const bool value);

        short getMaxLogHistory() const;

        bool setMaxLogHistory(const short value);

        std::string getTimeFormat() const;

        bool setTimeFormat(const std::string value);

        std::string getDesktopSearchPath() const;

        bool setDesktopSearchPath(const std::string value);


        private:        
        unsigned short percentOverlayFill;

        LogLevelE logLevel;

        std::string logDir;

        std::string logFilePrefix;

        bool logToStdout;
        
        bool logToStderr;

        short maxLogHistory;

        std::string timeFormat;

        std::string desktopSearchPath;
    };
}

#endif /* CONFIG_HPP */
