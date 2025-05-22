//
// Created by philipp on 21.05.25.
//

#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H
#include <string>
#include <sstream>
#include <vector>

#include "ServiceContainer.h"

class CommandProcessor {
public:
    CommandProcessor();
    CommandProcessor(const std::string &command, int day);

    bool isCommand();
    void processCommand();

private:
    int day{};
    std::string command;
    std::vector<std::string> tokens;

    void tokenize();
    void processTokenizedCommand();

    void deleteTodo(int index);
    void checkTodo(int index);
    void uncheckTodo(int index);
    void setPrio(int index, int prio);
    void save();
    void help();
    void clear();
    void pomo();
};



#endif //COMMANDPROCESSOR_H
