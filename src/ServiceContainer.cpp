//
// Created by philipp on 21.05.25.
//

#include "ServiceContainer.h"

std::shared_ptr<TodoService> ServiceContainer::todoService = nullptr;
std::shared_ptr<WindowStateHandler> ServiceContainer::windowStateHandler = nullptr;

void ServiceContainer::initialize() {
    todoService = std::make_shared<TodoService>();
    windowStateHandler = std::make_shared<WindowStateHandler>();
}
