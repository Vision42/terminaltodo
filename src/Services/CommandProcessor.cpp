//
// Created by philipp on 21.05.25.
//

#include "CommandProcessor.h"

#include <strings.h>

#include "DTO/WindowState.h"

CommandProcessor::CommandProcessor() = default;

CommandProcessor::CommandProcessor(const std::string &command, int day) {
    this->command = command;
    this->day = day;
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

    if (tokens[0] == ":prio") {
        setPrio(std::stoi(tokens[1]), std::stoi(tokens[2]));
        return;
    }

    if (tokens[0] == ":save") {
        save();
        return;
    }

    if (tokens[0] == ":help") {
        help();
        return;
    }

    if (tokens[0] == ":clear") {
        clear();
    }

    if (tokens[0] == ":pomo") {
        pomo();
    }
}

void CommandProcessor::deleteTodo(int index) {
    ServiceContainer::todoService->deleteTodo(index, day);
}

void CommandProcessor::checkTodo(int index) {
    ServiceContainer::todoService->checkTodo(index, day);
}

void CommandProcessor::uncheckTodo(int index) {
    ServiceContainer::todoService->uncheckTodo(index, day);
}

void CommandProcessor::setPrio(int index, int prio) {
    ServiceContainer::todoService->setPrio(index, day, prio);
}

void CommandProcessor::save() {
    ServiceContainer::todoService->save();
}

void CommandProcessor::help() {
    ServiceContainer::windowStateHandler->switchWindow(WindowState::HELP);
}

void CommandProcessor::clear() {
    ServiceContainer::todoService->clear();
}

void CommandProcessor::pomo() {
    ServiceContainer::windowStateHandler->switchWindow(WindowState::POMO);
}
