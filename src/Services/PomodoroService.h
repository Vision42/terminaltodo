//
// Created by philipp on 23.05.25.
//

#ifndef POMODOROSERVICE_H
#define POMODOROSERVICE_H

#include <chrono>
#include <string>

class PomodoroService {
public:
    PomodoroService();
    void startClock();
    void startNextPhase();
    void stopClock();
    void resetClock();
    void skipSection();
    std::string getElapsedTime();
    [[nodiscard]] std::string getCurrentPhase() const;
    [[nodiscard]] bool clockRunning() const;
    [[nodiscard]] bool readyForNextPhase() const;
    [[nodiscard]] int getCycles() const;

private:
    const uint8_t POM_TIME = 25;
    const uint8_t SHORT_BRAKE_TIME = 5;
    const uint8_t LONG_BRAKE_TIME = 10;

    int currentPhase;
    int targetPhase;
    int cycles;

    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::microseconds elapsedTime{};
    bool running;

    void checkPhases();
    [[nodiscard]] std::chrono::microseconds getTimeToGo() const;
    [[nodiscard]] std::chrono::microseconds getTimespanForCurrentPhase() const;
};



#endif //POMODOROSERVICE_H
