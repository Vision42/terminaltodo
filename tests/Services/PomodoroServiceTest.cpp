//
// Created by philipp on 26.05.25.
//

#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include "Services/PomodoroService.h"

class PomodoroServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        service.resetClock();
    }

    PomodoroService service;
};

TEST_F(PomodoroServiceTest, ClockStartsCorrectly) {
    EXPECT_FALSE(service.clockRunning());
    service.startClock();
    EXPECT_TRUE(service.clockRunning());
}

TEST_F(PomodoroServiceTest, ClockStopsCorrectly) {
    service.startClock();
    service.stopClock();
    EXPECT_FALSE(service.clockRunning());
}

TEST_F(PomodoroServiceTest, ResetResetsState) {
    service.startClock();
    service.skipPhase();
    service.resetClock();
    EXPECT_FALSE(service.clockRunning());
    EXPECT_EQ(service.getCurrentPhase(), "Pomodoro");
    EXPECT_EQ(service.getCycles(), 1);
}

TEST_F(PomodoroServiceTest, ReadyForNextPhaseWorks) {
    EXPECT_FALSE(service.readyForNextPhase());
    service.skipPhase();
    EXPECT_FALSE(service.readyForNextPhase());
}

TEST_F(PomodoroServiceTest, ElapsedTimeFormattingIsCorrect) {
    service.startClock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    auto elapsed = service.getElapsedTime();
    // Not checking exact value — just that format is correct
    EXPECT_EQ(elapsed.length(), 5);
    EXPECT_EQ(elapsed[2], ':');
}

TEST_F(PomodoroServiceTest, PhaseLabelReturnsCorrectString) {
    EXPECT_EQ(service.getCurrentPhase(), "Pomodoro");
    EXPECT_EQ(service.getNextPhase(), "Short brake");
}
