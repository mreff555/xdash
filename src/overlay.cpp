#include <overlay.hpp>
#include <config.hpp>
#include <logger.hpp>
#include <trigger.hpp>

// Just to make the thread sleep for test purposes
#include <chrono>
#include <thread>

using namespace xdash;

// Debug
std::string TEST_IMAGE_LOCATION = "/usr/share/gimp/2.0/icons/Color/64x64/apps/gimp-question.png";


Overlay::Overlay(std::shared_ptr<Config> config,
    std::shared_ptr<Logger> logger,
    std::shared_ptr<Trigger> trigger)
: mConfig(config), mLogger(logger), mTrigger(trigger),
mDisplay(XOpenDisplay(NULL)),
mRootWindow(DefaultRootWindow(mDisplay)),
mDefaultScreen(XDefaultScreen(mDisplay))
{
    this->mAttrs.override_redirect = true;
    if (!XMatchVisualInfo(mDisplay, DefaultScreen(mDisplay), 32, TrueColor, &mVinfo))
    {
        printf("No visual found supporting 32 bit color, terminating\n");
        exit(EXIT_FAILURE);
    }
    
    this->mAttrs.colormap = XCreateColormap(mDisplay, mRootWindow, mVinfo.visual, AllocNone);
    this->mAttrs.background_pixel = 0;
    this->mAttrs.border_pixel = 0;

    XGetWindowAttributes(mDisplay, mRootWindow, &mRootWindowAttributes);
}

Overlay::~Overlay()
{
    XCloseDisplay(this->mDisplay);
}

void Overlay::drawOverlay()
{
    // Calculate dimensions for the overlay window based
    double wFill = static_cast<double>(mConfig->getPercentOverlayFill() / 100.0);
    double rWidth = static_cast<double>(this->mRootWindowAttributes.width);
    double rHeight = static_cast<double>(this->mRootWindowAttributes.height);
    printf("Percent fill: %d(%f)\n", mConfig->getPercentOverlayFill(), wFill);
    int x = static_cast<unsigned>((rWidth - (rWidth * wFill)) / 2.0);
    int y = static_cast<unsigned>((rHeight - (rHeight * wFill)) / 2.0);
    int w = static_cast<unsigned>(rWidth * wFill);
    int h = static_cast<unsigned>(rHeight * wFill);
    printf("Root window: %f x %f - %f\n", rWidth, rHeight, wFill);
    printf("x/y/w/h: %d x %d x %d x %d\n", x, y, w, h);

    Window overlay = XCreateWindow(
        this->mDisplay, this->mRootWindow,
        x, y, w, h, 0,
        this->mVinfo.depth, InputOutput,
        this->mVinfo.visual,
        CWOverrideRedirect | CWColormap | CWBackPixel | CWBorderPixel, &mAttrs
    );
    XMapWindow(this->mDisplay, overlay);
    cairo_surface_t* surf = cairo_xlib_surface_create(
        this->mDisplay, overlay,
        this->mVinfo.visual,
        w, h);
    cairo_t* cr = cairo_create(surf);
    cairo_set_source_rgba(cr, 0.0, 3.0, 7.0, 1.0);
    cairo_rectangle(cr, 0, 0, w, h);
    cairo_fill(cr);
   
    placeIcon(cr, TEST_IMAGE_LOCATION, 20, 20);
    // cairo_surface_t *icon = cairo_image_surface_create_from_png(TEST_IMAGE_LOCATION.c_str());
    // cairo_set_source_surface(cr, icon, 20, 20);
    cairo_paint(cr);


    XFlush(mDisplay);

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    cairo_destroy(cr);
    cairo_surface_destroy(surf);
    XUnmapWindow(mDisplay, overlay);
}

void Overlay::placeIcon(cairo_t *cr, std::string img, int x, int y)
{
    cairo_surface_t *icon = cairo_image_surface_create_from_png(img.c_str());
    // handle errors
    int iconWidth = cairo_image_surface_get_width(icon);
    int iconHeight = cairo_image_surface_get_height(icon);

    cairo_set_source_surface(cr, icon, x, y);
}

