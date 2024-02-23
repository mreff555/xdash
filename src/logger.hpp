#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <memory>

namespace xdash
{
    class Config config();
    class Logger
    {
        public:
        Logger(std::shared_ptr<Config> config);

        virtual ~Logger() = default;

        private:
        std::shared_ptr<Config> mConfig;
    };
}

#endif /* LOGGER_HPP */
