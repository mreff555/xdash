// *** EXAMPLE ***
// [Desktop Entry]
// Name=Typora
// GenericName=Markdown Editor
// Exec=typora %U
// Icon=typora
// Type=Application
// StartupNotify=true
// Categories=Office;WordProcessor;
// MimeType=text/markdown;text/x-markdown;

#ifndef DESKTOP_ENTRY_HPP
#define DESKTOP_ENTRY_HPP

#include <string>

namespace xdash
{
    struct DesktopEntry
    {
        std::string name;
        std::string genericName;
        std::string exec;
        std::string icon;
        std::string type;
        std::string application;
        std::string startupNotify;
        std::string catagories;
        std::string mimeTypes;
    };
}

#endif /* DESKTOP_ENTRY_HPP */
