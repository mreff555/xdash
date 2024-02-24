#ifndef LOGLEVEL_HPP
#define LOGLEVEL_HPP

namespace xdash
{
    enum LogLevelE
    {
        LOG_LEVEL_FATAL,        // crash data and stack traces
        LOG_LEVEL_WARNING,      // non-fatal issues the user should be aware of
        LOG_LEVEL_INFO,         // relevant runtime data
        LOG_LEVEL_LOGIC,        // relevant but possibly verbose data
        LOG_LEVEL_DEBUG,        // verbose debug data
        LOG_LEVEL_TRACE,        // everything, for example entering and exiting functions
        LOG_LEVEL_MAX           // not intended to be a utilized level. should mirror trace behavior.
    };
}

#endif /* LOGLEVEL_HPP */