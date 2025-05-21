//
// Created by philipp on 21.05.25.
//

#include "CommandProcessor.h"

#include "ServiceContainer.h"

CommandProcessor::CommandProcessor() = default;

CommandProcessor::CommandProcessor(const std::string &command) {
    this->command = command;
}

bool CommandProcessor::isCommand() {
    if (command.empty()) {
        return false;
    }

    if (command[0] != ':') {
        return false;
    }

    return true;
}

void CommandProcessor::processCommand() {
    tokenize();
    processTokenizedCommand();
}

void CommandProcessor::tokenize() {
    std::istringstream iss{command};
    std::string token;

    while (iss >> token) {
        tokens.push_back(token);
    }
}

void CommandProcessor::processTokenizedCommand() {
    if (tokens[0] == ":delete") {
        deleteTodo(std::stoi(tokens[1]));
        return;
    }

    if (tokens[0] == ":check") {
        checkTodo(std::stoi(tokens[1]));
        return;
    }

    if (tokens[0] == ":uncheck") {
        uncheckTodo(std::stoi(tokens[1]));
        return;
    }
}

void CommandProcessor::deleteTodo(int index) {
    ServiceContainer::todoService->deleteTodo(index);
}

void CommandProcessor::checkTodo(int index) {
    ServiceContainer::todoService->checkTodo(index);
}

void CommandProcessor::uncheckTodo(int index) {
    ServiceContainer::todoService->uncheckTodo(index);
}
