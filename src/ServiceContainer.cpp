//
// Created by philipp on 21.05.25.
//

#include "ServiceContainer.h"

std::shared_ptr<ITodoService> ServiceContainer::todoService = nullptr;
std::shared_ptr<IWindowStateHandler> ServiceContainer::windowStateHandler = nullptr;
std::shared_ptr<PomodoroService> ServiceContainer::pomodoroService = nullptr;
std::shared_ptr<AudioService> ServiceContainer::audioService = nullptr;
std::shared_ptr<IConfigService> ServiceContainer::configService = nullptr;

void ServiceContainer::initialize() {
    configService = std::make_shared<ConfigService>();
    todoService = std::make_shared<TodoService>();
    windowStateHandler = std::make_shared<WindowStateHandler>();
    pomodoroService = std::make_shared<PomodoroService>();
    audioService = std::make_shared<AudioService>();
}
