//
// Created by philipp on 23.05.25.
//

#ifndef TIMEDSCREENREFRESHER_H
#define TIMEDSCREENREFRESHER_H

#include <ftxui/component/screen_interactive.hpp>
#include <thread>
#include <chrono>

class TimedScreenRefresher {
public:
    TimedScreenRefresher() = delete;
    TimedScreenRefresher(ftxui::ScreenInteractive &screen, int delay, int targetScreen) : screen(screen), delay(delay), targetScreen(targetScreen) {};
    void start();
    void stop();

private:
    std::thread timedScreenRefresherThread;
    ftxui::ScreenInteractive &screen;
    int delay;
    int targetScreen;
    bool stopped = false;

    void refresh();
};



#endif //TIMEDSCREENREFRESHER_H
