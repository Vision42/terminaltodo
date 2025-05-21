//
// Created by philipp on 21.05.25.
//

#ifndef TODOSERVICE_H
#define TODOSERVICE_H

#include <string>
#include <vector>

#include "DTO/TodoContainer.h"
#include "DTO/TODOElement.h"

class TodoService {
public:
    TodoService();

    void addTodo(const std::string &content, int day);
    void deleteTodo(int index, int day);
    void checkTodo(int index, int day);
    void uncheckTodo(int index, int day);
    std::vector<std::vector<std::string>> getTodoTable(int day);

    ~TodoService();

private:
    std::vector<TodoContainer> todoContainers;
};



#endif //TODOSERVICE_H
