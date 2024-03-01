#include <appds.hpp>
#include <config.hpp>
#include <logger.hpp>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <cstdio>
#include <cstdlib>


using namespace xdash;

AppDs::AppDs(
    std::shared_ptr<Config> config,
    std::shared_ptr<Logger> logger)
:mConfig(config), mLogger(logger),
desktopSearchPath(mConfig->getDesktopSearchPath())
{
    mLogger->log(LOG_LEVEL_INFO, "Starting AppDs");
}

AppDs::~AppDs()
{
    mLogger->log(LOG_LEVEL_INFO, "Stopping AppDs");
}

void AppDs::importDesktopEntries()
{
    mLogger->log(LOG_LEVEL_TRACE, "Entering importDesktopEntries()");
    typedef std::vector<std::string> stringvec;

    // Parse file paths into a vector
    std::string delimiter = ":";
    size_t next = 0;
    size_t last = 0;
    stringvec desktopPaths;
    while((next = this->desktopSearchPath.find(delimiter, last)) != std::string::npos )
    {
        desktopPaths.push_back(desktopSearchPath.substr(last, next - last));
        mLogger->log(LOG_LEVEL_DEBUG, "Found Desktop path: %s", desktopPaths.back().c_str());
        last = next + 1;
    }
    desktopPaths.push_back(desktopSearchPath.substr(last));
    mLogger->log(LOG_LEVEL_DEBUG, "Found Desktop path: %s", desktopPaths.back().c_str());


    // Parse all desktop files into a vector;
    stringvec desktopFiles;
    struct dirent *dp = nullptr;
    for(auto desktopPath : desktopPaths)
    {
        mLogger->log(LOG_LEVEL_DEBUG, "Opening directory: %s", desktopPath.c_str());
        DIR* dirp = opendir(desktopPath.c_str());

        while((dp = readdir(dirp)) != NULL)
        {
            // std::string s(desktopPath + "/");
            // s += std::string(dp->d_name);
            // mLogger->log(LOG_LEVEL_DEBUG, "Found desktop path: %s\n", s.c_str());
            // desktopFiles.push_back(s);
        }
        closedir(dirp);
    }

    // // Read in each file and parse to ini


}