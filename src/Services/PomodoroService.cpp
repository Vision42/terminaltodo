//
// Created by philipp on 23.05.25.
//

#include "PomodoroService.h"

#include "Formatter.h"
#include "ServiceContainer.h"
#include "DTO/PomodoroPhases.h"

PomodoroService::PomodoroService() {
    startTime = {};
    elapsedTime = std::chrono::microseconds::zero();
    running = false;
    currentPhase = PomodoroPhases::POMODORO;
    targetPhase = PomodoroPhases::POMODORO;
}

void PomodoroService::startClock() {
    startTime = std::chrono::high_resolution_clock::now();
    running = true;
}

void PomodoroService::startNextPhase() {
    currentPhase = targetPhase;
    startClock();
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
    checkPhases();

    return Formatter::formatMicroseconds(getTimeToGo());
}

std::string PomodoroService::getCurrentPhase() const {
    switch (currentPhase) {
        case PomodoroPhases::POMODORO:
            return "Pomodoro";
        case PomodoroPhases::SHORT_BRAKE:
            return "Short brake";
        case PomodoroPhases::LONG_BRAKE:
            return "Long brake";
        default: return "";
    }
}

void PomodoroService::checkPhases() {
    if (currentPhase != targetPhase) {
        return;
    }

    if (getTimeToGo().count() > 0) {
        return;
    }

    targetPhase = currentPhase + 1 > PomodoroPhases::LONG_BRAKE ? PomodoroPhases::POMODORO : currentPhase + 1;
    ServiceContainer::audioService->playNotificationSound();
}

bool PomodoroService::clockRunning() const {
    return running;
}

bool PomodoroService::readyForNextPhase() const {
    return currentPhase != targetPhase;
}

std::chrono::microseconds PomodoroService::getTimeToGo() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(getTimespanForCurrentPhase() - elapsedTime);
}

std::chrono::microseconds PomodoroService::getTimespanForCurrentPhase() const {
    return std::chrono::microseconds{static_cast<long>(POM_TIME * 6e7)};
}
