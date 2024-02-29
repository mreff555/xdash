#include <appds.hpp>
#include <config.hpp>
#include <logger.hpp>
using namespace xdash;

AppDs::AppDs(
    std::shared_ptr<Config> config,
    std::shared_ptr<Logger> logger)
:mConfig(config), mLogger(logger)
{
    mLogger->log(LOG_LEVEL_INFO, "Starting AppDs");
}

AppDs::~AppDs()
{
    mLogger->log(LOG_LEVEL_INFO, "Stopping AppDs");
}