//
// Created by philipp on 21.05.25.
//

#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H
#include <string>
#include <sstream>
#include <vector>



class CommandProcessor {
public:
    CommandProcessor();
    CommandProcessor(const std::string &command);

    bool isCommand();
    void processCommand();

private:
    std::string command;
    std::vector<std::string> tokens;

    void tokenize();
    void processTokenizedCommand();

    void deleteTodo(int index);
    void checkTodo(int index);
    void uncheckTodo(int index);
};



#endif //COMMANDPROCESSOR_H
