//
// Created by philipp on 23.05.25.
//

#include "PomodoroService.h"

#include "Formatter.h"

PomodoroService::PomodoroService() {
    startTime = {};
    elapsedTime = std::chrono::microseconds::zero();
    running = false;
}

void PomodoroService::startClock() {
    startTime = std::chrono::high_resolution_clock::now();
    running = true;
}

void PomodoroService::stopClock() {
    running = false;
}

void PomodoroService::resetClock() {
}

void PomodoroService::skipSection() {
}

std::string PomodoroService::getElapsedTime() {
    if (! running) {
        return Formatter::formatMicroseconds(elapsedTime);
    }

    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(currentTime - startTime);

    elapsedTime = duration;

    return Formatter::formatMicroseconds(elapsedTime);
}

std::string PomodoroService::getCurrentPhase() {
    return "not implemented";
}

bool PomodoroService::clockRunning() {
    return running;
}
