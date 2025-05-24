//
// Created by philipp on 22.05.25.
//

#include "PomodoroRenderer.h"

#include "ServiceContainer.h"

PomodoroRenderer::PomodoroRenderer(ScreenInteractive &screen): Renderer(screen), timedRefresher(screen, 500, WindowState::POMO) {
    auto component = Container::Stacked({
            btnReset,
            btnSkipPhase,
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
        hbox(
            text("Cycles: " + std::to_string(ServiceContainer::pomodoroService->getCycles())) | center | flex,
            text("Current phase: " + ServiceContainer::pomodoroService->getCurrentPhase()) | center | flex,
            text("Next phase: " + ServiceContainer::pomodoroService->getNextPhase()) | center | flex
        ),
        separator(),
        hbox(btnReset->Render() | center| flex, btnSkipPhase->Render() | center | flex),
    }));
}

std::string PomodoroRenderer::getElapsedTime() {
    return ServiceContainer::pomodoroService->getElapsedTime();
}

bool PomodoroRenderer::handleSpacePress(const Event &e) {
    if (e == Event::Character(' ')) {
        if (ServiceContainer::pomodoroService->clockRunning() && !ServiceContainer::pomodoroService->readyForNextPhase()) {
            timedRefresher.stop();
            ServiceContainer::pomodoroService->stopClock();
            return true;
        }

        if (ServiceContainer::pomodoroService->readyForNextPhase()) {
            ServiceContainer::pomodoroService->startNextPhase();
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

void PomodoroRenderer::skipPhase() {
    ServiceContainer::pomodoroService->skipPhase();
}
