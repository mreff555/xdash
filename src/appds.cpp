#include <appds.hpp>
#include <config.hpp>
#include <logger.hpp>
using namespace xdash;

AppDs::AppDs(std::shared_ptr<Config> config, std::shared_ptr<Logger> logger)
:mConfig(config), mLogger(logger)
{}
