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
    void skipPhase();
    std::string getElapsedTime();
    [[nodiscard]] std::string getCurrentPhase() const;
    [[nodiscard]] std::string getNextPhase() const;
    [[nodiscard]] bool clockRunning() const;
    [[nodiscard]] bool readyForNextPhase() const;
    [[nodiscard]] int getCycles() const;
    [[nodiscard]] float getProgress() const;

private:
    uint8_t POM_TIME = 25;
    uint8_t SHORT_BRAKE_TIME = 5;
    uint8_t LONG_BRAKE_TIME = 10;

    int currentPhase;
    int targetPhase;
    int cycles;

    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::microseconds elapsedTime{};
    bool running;

    void checkPhases();
    void moveToNextPhase();
    [[nodiscard]] std::chrono::microseconds getTimeToGo() const;
    [[nodiscard]] std::chrono::microseconds getTimespanForCurrentPhase() const;
    [[nodiscard]] static std::string getPhaseLabel(int phase) ;
};



#endif //POMODOROSERVICE_H
