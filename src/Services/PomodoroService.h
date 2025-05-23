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
    void stopClock();
    void resetClock();
    void skipSection();
    std::string getElapsedTime();
    std::string getCurrentPhase();
    bool clockRunning();

private:
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::microseconds elapsedTime;
    bool running;
};



#endif //POMODOROSERVICE_H
