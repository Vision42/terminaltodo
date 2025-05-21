//
// Created by philipp on 21.05.25.
//

#ifndef SERVICECONTAINER_H
#define SERVICECONTAINER_H
#include <memory>

#include "Services/TodoService.h"


class ServiceContainer {
public:
    static std::shared_ptr<TodoService> todoService;

    static void initialize();
    ServiceContainer() = delete;
};



#endif //SERVICECONTAINER_H
