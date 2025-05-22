//
// Created by philipp on 22.05.25.
//

#ifndef HELPRENDERER_H
#define HELPRENDERER_H

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <string>

#include "ftxui/component/component.hpp"

using namespace ftxui;

class HelpRenderer {
public:
    HelpRenderer() = delete;
    HelpRenderer(ScreenInteractive &screen);

    Component getRenderer();

private:
    ScreenInteractive &screen;
    Component renderer;

    Element refreshWindow();
};



#endif //HELPRENDERER_H
