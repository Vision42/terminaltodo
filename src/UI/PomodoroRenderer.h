//
// Created by philipp on 22.05.25.
//

#ifndef POMODORORENDERER_H
#define POMODORORENDERER_H

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include "ftxui/component/component.hpp"
#include <string>

#include "Renderer.h"
#include "DTO/WindowState.h"
#include "Services/TimedScreenRefresher.h"

using namespace ftxui;

class PomodoroRenderer : public Renderer {
public:
    PomodoroRenderer() = delete;
    PomodoroRenderer(ScreenInteractive &screen);

private:
    TimedScreenRefresher timedRefresher;

    Component btnReset = Button("Reset timer", [&] {
        resetTimer();
    });
    Component btnSkipPhase = Button("Skip phase", [&] {
        skipPhase();
    });

    Element refreshWindow();
    bool handleSpacePress(const Event &e);
    std::string getElapsedTime();
    void resetTimer();
    static void skipPhase();
};



#endif //POMODORORENDERER_H
