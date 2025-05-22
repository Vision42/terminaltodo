//
// Created by philipp on 21.05.25.
//

#include "MainWindow.h"

#include "HelpRenderer.h"
#include "TodoRenderer.h"
#include "DTO/WindowState.h"
#include "ftxui/component/component_base.hpp"
#include "Services/CommandProcessor.h"

using namespace ftxui;

MainWindow::MainWindow() {

}

void MainWindow::show(int window) {
    TodoRenderer todoRenderer(screen);
    HelpRenderer helpRenderer(screen);

    switch (window) {
        case WindowState::TODO:
            ServiceContainer::windowStateHandler->setActiveWindow(window);
            screen.Loop(todoRenderer.getRenderer());
            break;
        case WindowState::HELP:
            ServiceContainer::windowStateHandler->setActiveWindow(window);
            screen.Loop(helpRenderer.getRenderer());
            break;
    }

    if (ServiceContainer::windowStateHandler->shouldSwitchWindow()) {
        show(ServiceContainer::windowStateHandler->getTargetWindow());
    }
}
