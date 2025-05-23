//
// Created by philipp on 21.05.25.
//

#ifndef SERVICECONTAINER_H
#define SERVICECONTAINER_H
#include <memory>

#include "Services/AudioService.h"
#include "Services/PomodoroService.h"
#include "Services/TodoService.h"
#include "Services/WindowStateHandler.h"


class ServiceContainer {
public:
    static std::shared_ptr<TodoService> todoService;
    static std::shared_ptr<WindowStateHandler> windowStateHandler;
    static std::shared_ptr<PomodoroService> pomodoroService;
    static std::shared_ptr<AudioService> audioService;

    static void initialize();
    ServiceContainer() = delete;
};



#endif //SERVICECONTAINER_H
