//
// Created by philipp on 22.05.25.
//

#include "PomodoroRenderer.h"

#include "ServiceContainer.h"

PomodoroRenderer::PomodoroRenderer(ScreenInteractive &screen): Renderer(screen) {
    auto component = Container::Stacked({
            btnReset,
        });

    renderer = ftxui::Renderer(component , [&] { return refreshWindow(); });
}

Element PomodoroRenderer::refreshWindow() {
    if (ServiceContainer::windowStateHandler->shouldSwitchWindow()) {
        screen.Exit();
    }

    return window(text("TODO-Board | Pomodoro"), vbox({
        hbox(text("20:10") | bold | center | flex),
        separator(),
        hbox(gauge(0.5) | flex),
        separator(),
        hbox(text("Round: 4") | center | flex, text("Next pause: 5 min") | center | flex),
        separator(),
        hbox(btnReset->Render() | center| flex)
    }));
}

void PomodoroRenderer::resetTimer() {
}
