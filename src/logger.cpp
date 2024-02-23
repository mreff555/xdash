#include <logger.hpp>
#include <config.hpp>

using namespace xdash;
Logger::Logger(std::shared_ptr<xdash::Config> config)
: mConfig(config)
{}
