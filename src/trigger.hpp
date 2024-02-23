#ifndef TRIGGER_HPP
#define TRIGGER_HPP
#include <memory>

namespace xdash
{
    class Config config();
    class Logger logger(std::shared_ptr<Config>);

    class Trigger
    {
        public:
        Trigger(
            std::shared_ptr<xdash::Config> config,
            std::shared_ptr<xdash::Logger> logger);

        virtual ~Trigger() = default;
        private:
        std::shared_ptr<Config> mConfig;
        std::shared_ptr<Logger> mLogger;
    };
}

#endif /* TRIGGER_HPP */