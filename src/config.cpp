#include <config.hpp>

using namespace xdash;
Config::Config()
: percentOverlayFill(DEFAULT_PERCENT_OVERLAY_FILL)
{

}

unsigned int Config::getPercentOverlayFill() const
{
    return this->percentOverlayFill;
}

bool Config::setPercentOverlayFill(const unsigned int value)
{
    bool rtn = false;
    if(value > 0 && value <= 100)
    {
        this->percentOverlayFill = value;
        rtn = true;
    }
    return rtn;
}
