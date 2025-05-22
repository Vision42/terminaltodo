//
// Created by philipp on 21.05.25.
//

#include "TodoService.h"

TodoService::TodoService() {
    for (size_t i = 0; i < 5; i++) {
        todoContainers.emplace_back();
    }
}

void TodoService::addTodo(const std::string &content, int day) {
    TODOElement element;
    element.content = content;
    element.priority = "MEDIUM";

    todoContainers[day].elements.push_back(element);
}

void TodoService::deleteTodo(int index, int day) {
    todoContainers[day].elements.erase(todoContainers[0].elements.begin() + index);
}

void TodoService::checkTodo(int index, int day) {
    todoContainers[day].elements[index].completed = true;
}

void TodoService::uncheckTodo(int index, int day) {
    todoContainers[day].elements[index].completed = false;
}

void TodoService::setPrio(int index, int day, int prio) {
    std::string label{};

    switch (prio) {
        case Priority::LOW: label = "LOW"; break;
        case Priority::MEDIUM: label = "MEDIUM"; break;
        case Priority::HIGH: label = "HIGH"; break;
        default: label = "NONE"; break;
    }

    todoContainers[day].elements[index].priority = label;
}

std::vector<std::vector<std::string>> TodoService::getTodoTable(int day) {
    std::vector<std::vector<std::string>> table;

    table.push_back(std::vector<std::string>{"ID", "Priority", "Content", "Completed"});

    for (size_t i = 0; i < todoContainers[day].elements.size(); i++) {
        auto [priority, content, completed] = todoContainers[day].elements[i];
        auto index = std::to_string(i);
        table.push_back(std::vector{index, priority, content, static_cast<std::string>(completed ? "\u2705" : "\u274C")});
    }

    return table;
}

TodoService::~TodoService() {
}
