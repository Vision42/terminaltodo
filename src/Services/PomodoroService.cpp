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
    cycles = 1;
}

void PomodoroService::startClock() {
    startTime = std::chrono::high_resolution_clock::now();
    running = true;
}

void PomodoroService::startNextPhase() {
    if (currentPhase != PomodoroPhases::POMODORO) {
        cycles++;
    }

    currentPhase = targetPhase;
    startClock();
}

void PomodoroService::stopClock() {
    running = false;
}

void PomodoroService::resetClock() {
    startTime = {};
    elapsedTime = std::chrono::microseconds::zero();
    currentPhase = PomodoroPhases::POMODORO;
    targetPhase = PomodoroPhases::POMODORO;
    running = false;
    cycles = 1;
}

void PomodoroService::skipPhase() {
    moveToNextPhase();
    startNextPhase();
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
    return getPhaseLabel(currentPhase);
}

std::string PomodoroService::getNextPhase() const {
    return getPhaseLabel(currentPhase + 1 <= PomodoroPhases::LONG_BRAKE ? currentPhase + 1 : PomodoroPhases::POMODORO);
}

void PomodoroService::checkPhases() {
    if (currentPhase != targetPhase) {
        return;
    }

    if (getTimeToGo().count() > 0) {
        return;
    }

    ServiceContainer::audioService->playNotificationSound();
    moveToNextPhase();
}

void PomodoroService::moveToNextPhase() {
    if (currentPhase == PomodoroPhases::SHORT_BRAKE || currentPhase == PomodoroPhases::LONG_BRAKE) {
        targetPhase = PomodoroPhases::POMODORO;
        return;
    }

    if (cycles % 4 == 0 && currentPhase == PomodoroPhases::POMODORO) {
        targetPhase = PomodoroPhases::LONG_BRAKE;
        return;
    }

    targetPhase = PomodoroPhases::SHORT_BRAKE;
}

bool PomodoroService::clockRunning() const {
    return running;
}

bool PomodoroService::readyForNextPhase() const {
    return currentPhase != targetPhase;
}

int PomodoroService::getCycles() const {
    return cycles;
}

float PomodoroService::getProgress() const {
    return  1.0f - (static_cast<float>(getTimeToGo().count()) / getTimespanForCurrentPhase().count());
}

std::chrono::microseconds PomodoroService::getTimeToGo() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(getTimespanForCurrentPhase() - elapsedTime);
}

std::chrono::microseconds PomodoroService::getTimespanForCurrentPhase() const {
    switch (currentPhase) {
        case PomodoroPhases::POMODORO: return std::chrono::microseconds{static_cast<long>(POM_TIME * 6e7)};
        case PomodoroPhases::SHORT_BRAKE: return std::chrono::microseconds{static_cast<long>(SHORT_BRAKE_TIME * 6e7)};
        case PomodoroPhases::LONG_BRAKE: return std::chrono::microseconds{static_cast<long>(LONG_BRAKE_TIME * 6e7)};
        default: return std::chrono::microseconds{0};
    }
}

std::string PomodoroService::getPhaseLabel(int phase) {
    switch (phase) {
        case PomodoroPhases::POMODORO:
            return "Pomodoro";
        case PomodoroPhases::SHORT_BRAKE:
            return "Short brake";
        case PomodoroPhases::LONG_BRAKE:
            return "Long brake";
        default: return "";
    }
}
