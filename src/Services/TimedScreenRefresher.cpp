//
// Created by philipp on 23.05.25.
//

#include "TimedScreenRefresher.h"

#include "ServiceContainer.h"

void TimedScreenRefresher::start() {
    stopped = false;

    timedScreenRefresherThread = std::thread(&TimedScreenRefresher::refresh, this);
    timedScreenRefresherThread.detach();
}

void TimedScreenRefresher::stop() {
    stopped = true;
}

void TimedScreenRefresher::refresh() {
    while (! stopped) {
        if (ServiceContainer::windowStateHandler->getTargetWindow() != targetScreen) {
            break;
        }

        screen.PostEvent(ftxui::Event::Custom);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}
