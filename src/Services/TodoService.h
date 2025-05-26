//
// Created by philipp on 21.05.25.
//

#ifndef TODOSERVICE_H
#define TODOSERVICE_H

#include <string>
#include <vector>

#include "DTO/TodoContainer.h"
#include "DTO/TODOElement.h"
#include "DTO/Priority.h"
#include "Interfaces/ITodoService.h"

class TodoService : public ITodoService {
public:
    TodoService();

    void addTodo(const std::string &content, int day) override;
    void deleteTodo(int index, int day) override;
    void checkTodo(int index, int day) override;
    void uncheckTodo(int index, int day) override;
    void setPrio(int index, int day, int prio) override;
    void save() override;
    void load() override;
    void clear() override;
    std::vector<std::vector<std::string>> getTodoTable(int day) override;

    ~TodoService() override;

private:
    std::vector<TodoContainer> todoContainers;
};



#endif //TODOSERVICE_H
