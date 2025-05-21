//
// Created by philipp on 21.05.25.
//

#ifndef TODOSERVICE_H
#define TODOSERVICE_H

#include <string>
#include <vector>

#include "DTO/TODOElement.h"

class TodoService {
public:
    TodoService();

    void addTodo(const std::string &content);
    void deleteTodo(int index);
    void checkTodo(int index);
    void uncheckTodo(int index);
    std::vector<std::vector<std::string>> getTodoTable();

    ~TodoService();

private:
    std::vector<TODOElement> todos;
};



#endif //TODOSERVICE_H
