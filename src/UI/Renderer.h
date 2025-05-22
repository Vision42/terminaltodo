//
// Created by philipp on 22.05.25.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

class Renderer {
public:
    Renderer() = delete;
    Renderer(ScreenInteractive &screen) : screen(screen) {}

    Component getRenderer() {
        return renderer;
    };

protected:
    ScreenInteractive &screen;
    Component renderer;
};



#endif //RENDERER_H
