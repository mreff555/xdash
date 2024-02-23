#ifndef OVERLAY_HPP
#define OVERLAY_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <cairo.h>
#include <cairo-xlib.h>
#include <string>
#include <memory>

namespace xdash
{
    class Config config();
    class Logger logger(std::shared_ptr<Config>);
    class Trigger trigger(std::shared_ptr<Config>, std::shared_ptr<Logger>);

    class Overlay
    {
        public:
        Overlay(std::shared_ptr<Config> config,
            std::shared_ptr<Logger> logger,
            std::shared_ptr<Trigger> trigger);

        virtual ~Overlay();

    void drawOverlay();

    private:
    void placeIcon(cairo_t *cr, std::string img, int x, int y);

    Display *mDisplay;
    Window mRootWindow;
    int mDefaultScreen;
    XSetWindowAttributes mAttrs;
    XVisualInfo mVinfo;
    XWindowAttributes mRootWindowAttributes;

    std::shared_ptr<Config> mConfig;
    std::shared_ptr<Logger> mLogger;
    std::shared_ptr<Trigger> mTrigger;
    };
}

#endif /* OVERLAY_HPP */