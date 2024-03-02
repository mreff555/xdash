#include <appds.hpp>
#include <config.hpp>
#include <logger.hpp>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
// #include <SimpleIni.h>



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
    for(auto desktopPath : desktopPaths)
    {
        using rdit = std::filesystem::recursive_directory_iterator;
        mLogger->log(LOG_LEVEL_DEBUG, "Entering Desktop path %s", desktopPath.c_str());
        if(std::filesystem::exists(desktopPath))
        {
            for(const auto &dirEntry : rdit(desktopPath))
            {
                if(dirEntry.is_regular_file())
                {
                    desktopFiles.push_back(dirEntry.path().string());
                    mLogger->log(LOG_LEVEL_DEBUG, "Found file: %s", desktopFiles.back().c_str());
                }
            }
        }
    }

    // Read in each file and parse to ini



}