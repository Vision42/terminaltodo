//
// Created by philipp on 26.05.25.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "Services/TodoService.h"
#include "Services/WindowStateHandler.h"
#include "Services/CommandProcessor.h"
#include "ServiceContainer.h"
#include "DTO/WindowState.h"

class MockTodoService : public ITodoService {
public:
    MOCK_METHOD(void, addTodo, (const std::string &content, int day), (override));
    MOCK_METHOD(void, deleteTodo, (int, int), (override));
    MOCK_METHOD(void, checkTodo, (int, int), (override));
    MOCK_METHOD(void, uncheckTodo, (int, int),(override));
    MOCK_METHOD(void, setPrio, (int, int, int), (override));
    MOCK_METHOD(void, save, (), (override));
    MOCK_METHOD(void, clear, (),(override));
    MOCK_METHOD(void, load, (),(override));
    MOCK_METHOD(std::vector<std::vector<std::string>>, getTodoTable, (int),(override));
};


class MockWindowStateHandler : public IWindowStateHandler {
public:
    MOCK_METHOD(void, switchWindow, (int), (override));
    MOCK_METHOD(void, setActiveWindow, (int), (override));
    MOCK_METHOD(bool, shouldSwitchWindow, (), (override));
    MOCK_METHOD(int, getTargetWindow, (), (override));
};

class CommandProcessorTest : public ::testing::Test {
protected:
    std::shared_ptr<MockTodoService> todoService = std::make_shared<MockTodoService>();
    std::shared_ptr<MockWindowStateHandler> windowStateHandler = std::make_shared<MockWindowStateHandler>();

    void SetUp() override {
        ServiceContainer::todoService = todoService;
        ServiceContainer::windowStateHandler = windowStateHandler;
    }

    void TearDown() override {
        ServiceContainer::todoService.reset();
        ServiceContainer::windowStateHandler.reset();

        todoService.reset();
        windowStateHandler.reset();
    }
};

TEST_F(CommandProcessorTest, DetectsCommand) {
    CommandProcessor cp(":save", 0);
    EXPECT_TRUE(cp.isCommand());

    CommandProcessor nonCommand("normal input", 0);
    EXPECT_FALSE(nonCommand.isCommand());
}

TEST_F(CommandProcessorTest, CallsDeleteTodo) {
    CommandProcessor cp(":delete 2", 1);
    EXPECT_CALL(*todoService, deleteTodo(2, 1));
    cp.processCommand();
}

TEST_F(CommandProcessorTest, CallsCheckTodo) {
    CommandProcessor cp(":check 3", 2);
    EXPECT_CALL(*todoService, checkTodo(3, 2));
    cp.processCommand();
}

TEST_F(CommandProcessorTest, CallsUncheckTodo) {
    CommandProcessor cp(":uncheck 4", 2);
    EXPECT_CALL(*todoService, uncheckTodo(4, 2));
    cp.processCommand();
}

TEST_F(CommandProcessorTest, CallsSetPrio) {
    CommandProcessor cp(":prio 1 2", 0);
    EXPECT_CALL(*todoService, setPrio(1, 0, 2));
    cp.processCommand();
}

TEST_F(CommandProcessorTest, CallsSave) {
    CommandProcessor cp(":save", 0);
    EXPECT_CALL(*todoService, save());
    cp.processCommand();
}

TEST_F(CommandProcessorTest, CallsClear) {
    CommandProcessor cp(":clear", 0);
    EXPECT_CALL(*todoService, clear());
    cp.processCommand();
}

TEST_F(CommandProcessorTest, SwitchesToHelpWindow) {
    CommandProcessor cp(":help", 0);
    EXPECT_CALL(*windowStateHandler, switchWindow(WindowState::HELP));
    cp.processCommand();
}

TEST_F(CommandProcessorTest, SwitchesToPomoWindow) {
    CommandProcessor cp(":pomo", 0);
    EXPECT_CALL(*windowStateHandler, switchWindow(WindowState::POMO));
    cp.processCommand();
}