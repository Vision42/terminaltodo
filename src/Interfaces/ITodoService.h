//
// Created by philipp on 26.05.25.
//

#ifndef ITODOSERVICE_H
#define ITODOSERVICE_H

#include <vector>
#include <string>

class ITodoService {
public:
    virtual void addTodo(const std::string &content, int day) = 0;
    virtual void deleteTodo(int index, int day) = 0;
    virtual void checkTodo(int index, int day) = 0;
    virtual void uncheckTodo(int index, int day) = 0;
    virtual void setPrio(int index, int day, int prio) = 0;
    virtual void save() = 0;
    virtual void load() = 0;
    virtual void clear() = 0;
    virtual std::vector<std::vector<std::string>> getTodoTable(int day) = 0;

    virtual ~ITodoService() = default;
};
#endif //ITODOSERVICE_H
