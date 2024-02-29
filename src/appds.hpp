#ifndef APP_DS_HPP
#define APP_DS_HPP

#include <desktopentry.hpp>
#include <string>
#include <list>
#include <algorithm>
#include <memory>

namespace xdash
{
    class Config config();
    class Logger logger(std::shared_ptr<Config>);

    // Sort() comparitor to sort desktop entries by name
    static bool compare_name(const DesktopEntry first, const DesktopEntry second)
    {
        /* Write me:  should be alphabetical should return true if first argument    */
        /* goes before the second                                                    */

    }

    class AppDs
    {
        public:
        AppDs(
            std::shared_ptr<Config> config,
            std::shared_ptr<Logger> logger);

        virtual ~AppDs();

        private:
        std::shared_ptr<Config> mConfig;
        std::shared_ptr<Logger> mLogger;
        std::string desktopSearchPath;
        std::list<DesktopEntry> desktopEntryList;
    };
}

#endif /* APP_DS_HPP */