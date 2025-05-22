//
// Created by philipp on 22.05.25.
//

#include "WindowStateHandler.h"

#include "DTO/WindowState.h"

WindowStateHandler::WindowStateHandler() {
    currentWindow = WindowState::TODO;
    targetWindow = WindowState::TODO;
}

void WindowStateHandler::switchWindow(int targetWindow) {
    this->targetWindow = targetWindow;
}

void WindowStateHandler::setActiveWindow(int window) {
    currentWindow = window;
}

bool WindowStateHandler::shouldSwitchWindow() {
    return targetWindow != currentWindow;
}

int WindowStateHandler::getTargetWindow() {
    return targetWindow;
}
