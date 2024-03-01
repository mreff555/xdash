// #include <xdash.hpp>

#include <appds.hpp>
#include <config.hpp>
#include <logger.hpp>
#include <trigger.hpp>
#include <overlay.hpp>

#include <memory>
#include <signal.h>
#include <string>
#include <thread>
#include <vector>

#include <memory>

namespace xdash
{
    auto config_p = std::make_shared<Config>();
    auto logger_p = std::make_shared<Logger>(config_p);
    auto appDs_p = std::make_shared<AppDs>(config_p, logger_p);
    auto trigger_p = std::make_shared<Trigger>(config_p, logger_p);
    //auto overlay_p = std::make_shared<Overlay>(config_p, logger_p, trigger_p);
}

int main(int argc, char** argv)
{
    // Xdash xd;
    // xd.drawOverlay();
    //xdash::overlay_p->drawOverlay();

    xdash::logger_p->setLogLevel(xdash::LOG_LEVEL_TRACE);
    xdash::appDs_p->importDesktopEntries();
}