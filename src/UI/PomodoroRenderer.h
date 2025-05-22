//
// Created by philipp on 22.05.25.
//

#ifndef POMODORORENDERER_H
#define POMODORORENDERER_H

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include "ftxui/component/component.hpp"

#include "Renderer.h"

using namespace ftxui;

class PomodoroRenderer : public Renderer {
public:
    PomodoroRenderer() = delete;
    PomodoroRenderer(ScreenInteractive &screen);

private:
    Element refreshWindow();
};



#endif //POMODORORENDERER_H
