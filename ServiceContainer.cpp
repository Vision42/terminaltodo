//
// Created by philipp on 21.05.25.
//

#include "ServiceContainer.h"

std::shared_ptr<TodoService> ServiceContainer::todoService = nullptr;

void ServiceContainer::initialize() {
    todoService = std::make_shared<TodoService>();
}
