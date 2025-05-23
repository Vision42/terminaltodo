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
        return Formatter::formatMicroseconds(getTimeToGo());
    }

    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(currentTime - startTime);

    elapsedTime = duration;

    return Formatter::formatMicroseconds(getTimeToGo());
}

std::string PomodoroService::getCurrentPhase() {
    return "not implemented";
}

bool PomodoroService::clockRunning() const {
    return running;
}

std::chrono::microseconds PomodoroService::getTimeToGo() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(getTimespanForCurrentPhase() - elapsedTime);
}

std::chrono::microseconds PomodoroService::getTimespanForCurrentPhase() const {
    return std::chrono::microseconds{static_cast<long>(POM_TIME * 6e7)};
}
