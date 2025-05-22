//
// Created by philipp on 21.05.25.
//

#include "MainWindow.h"

#include "HelpRenderer.h"
#include "PomodoroRenderer.h"
#include "TodoRenderer.h"
#include "DTO/WindowState.h"
#include "Services/CommandProcessor.h"

using namespace ftxui;

MainWindow::MainWindow() {

}

void MainWindow::show(int window) {
    TodoRenderer todoRenderer(screen);
    HelpRenderer helpRenderer(screen);
    PomodoroRenderer pomodoroRenderer(screen);

    switch (window) {
        case WindowState::TODO:
            ServiceContainer::windowStateHandler->setActiveWindow(window);
            screen.Loop(todoRenderer.getRenderer());
            break;
        case WindowState::HELP:
            ServiceContainer::windowStateHandler->setActiveWindow(window);
            screen.Loop(helpRenderer.getRenderer());
            break;
        case WindowState::POMO:
            ServiceContainer::windowStateHandler->setActiveWindow(window);
            screen.Loop(pomodoroRenderer.getRenderer());
            break;
    }

    if (ServiceContainer::windowStateHandler->shouldSwitchWindow()) {
        show(ServiceContainer::windowStateHandler->getTargetWindow());
    }
}
