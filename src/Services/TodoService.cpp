//
// Created by philipp on 21.05.25.
//

#include "TodoService.h"

TodoService::TodoService() {
}

void TodoService::addTodo(const std::string &content) {
    TODOElement element;
    element.content = content;
    element.priority = "none";

    todos.push_back(element);
}

void TodoService::deleteTodo(int index) {
    todos.erase(todos.begin() + index);
}

void TodoService::checkTodo(int index) {
    todos[index].completed = true;
}

void TodoService::uncheckTodo(int index) {
    todos[index].completed = false;
}

std::vector<std::vector<std::string>> TodoService::getTodoTable() {
    std::vector<std::vector<std::string>> table;

    table.push_back(std::vector<std::string>{"ID", "Priority", "Content", "Completed"});

    for (size_t i = 0; i < todos.size(); i++) {
        auto [priority, content, completed] = todos[i];
        auto index = std::to_string(i);
        table.push_back(std::vector{index, priority, content, static_cast<std::string>(completed ? "Y" : "x")});
    }

    return table;
}

TodoService::~TodoService() {
}
