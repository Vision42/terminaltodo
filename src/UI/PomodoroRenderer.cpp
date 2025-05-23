//
// Created by philipp on 22.05.25.
//

#include "PomodoroRenderer.h"

#include "ServiceContainer.h"

PomodoroRenderer::PomodoroRenderer(ScreenInteractive &screen): Renderer(screen), timedRefresher(screen, 500, WindowState::POMO) {
    auto component = Container::Stacked({
            btnReset,
        });

    renderer = ftxui::Renderer(component , [&] { return refreshWindow(); });
    renderer |= CatchEvent([&] (const Event &event) { return handleSpacePress(event); } );
}

Element PomodoroRenderer::refreshWindow() {
    if (ServiceContainer::windowStateHandler->shouldSwitchWindow()) {
        screen.Exit();
    }

    return window(text("TODO-Board | Pomodoro"), vbox({
        hbox(text(getElapsedTime()) | bold | center | flex),
        separator(),
        hbox(gauge(0.5) | flex),
        separator(),
        hbox(text("Round: 4") | center | flex, text("Next pause: 5 min") | center | flex),
        separator(),
        hbox(btnReset->Render() | center| flex)
    }));
}

std::string PomodoroRenderer::getElapsedTime() {
    return ServiceContainer::pomodoroService->getElapsedTime();
}

bool PomodoroRenderer::handleSpacePress(const Event &e) {
    if (e == Event::Character(' ')) {
        if (ServiceContainer::pomodoroService->clockRunning()) {
            timedRefresher.stop();
            ServiceContainer::pomodoroService->stopClock();
            return true;
        }

        timedRefresher.start();
        ServiceContainer::pomodoroService->startClock();

        return true;
    }

    return false;
}

void PomodoroRenderer::resetTimer() {
}
