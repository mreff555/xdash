#include <trigger.hpp>
#include <config.hpp>
#include <logger.hpp>

using namespace xdash;
Trigger::Trigger(
    std::shared_ptr<xdash::Config> config,
    std::shared_ptr<xdash::Logger> logger)
: mConfig(config), mLogger(logger)
{
    int num = 5;
    mLogger->log(LOG_LEVEL_INFO, "Starting Trigger");
    
}