//
// Created by philipp on 22.05.25.
//

#include "PomodoroRenderer.h"

#include "ServiceContainer.h"

PomodoroRenderer::PomodoroRenderer(ScreenInteractive &screen): Renderer(screen) {
    auto component = Container::Stacked({

        });

    renderer = ftxui::Renderer(component , [&] { return refreshWindow(); });
}

Element PomodoroRenderer::refreshWindow() {
    if (ServiceContainer::windowStateHandler->shouldSwitchWindow()) {
        screen.Exit();
    }

    return window(text("TODO-Board | Pomodoro"), vbox({
        hbox(paragraph("text")),
    }));
}
