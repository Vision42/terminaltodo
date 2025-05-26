//
// Created by philipp on 26.05.25.
//

#include <gtest/gtest.h>
#include "Services/WindowStateHandler.h"
#include "DTO/WindowState.h"

class WindowStateHandlerTest : public ::testing::Test {
protected:
    WindowStateHandler handler;
};

TEST_F(WindowStateHandlerTest, InitializesToTodoWindow) {
    EXPECT_FALSE(handler.shouldSwitchWindow());
    EXPECT_EQ(handler.getTargetWindow(), WindowState::TODO);
}

TEST_F(WindowStateHandlerTest, SwitchesWindowSetsTarget) {
    handler.switchWindow(WindowState::POMO);
    EXPECT_EQ(handler.getTargetWindow(), WindowState::POMO);
    EXPECT_TRUE(handler.shouldSwitchWindow());
}

TEST_F(WindowStateHandlerTest, NoSwitchIfTargetEqualsCurrent) {
    handler.switchWindow(WindowState::TODO);
    EXPECT_FALSE(handler.shouldSwitchWindow());
}

TEST_F(WindowStateHandlerTest, SetActiveWindowPreventsSwitch) {
    handler.switchWindow(WindowState::HELP);
    EXPECT_TRUE(handler.shouldSwitchWindow());

    handler.setActiveWindow(WindowState::HELP);
    EXPECT_FALSE(handler.shouldSwitchWindow());
}
