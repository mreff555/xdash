#ifndef APP_DS_HPP
#define APP_DS_HPP
#include <memory>

namespace xdash
{
    class Config config();
    class Logger logger(std::shared_ptr<Config>);

    class AppDs
    {
        public:
        AppDs(
            std::shared_ptr<Config> config,
            std::shared_ptr<Logger> logger);

        virtual ~AppDs() = default;

        private:
        std::shared_ptr<Config> mConfig;
        std::shared_ptr<Logger> mLogger;
    };
}

#endif /* APP_DS_HPP */