//
// Created by philipp on 25.05.25.
//

#include <gtest/gtest.h>
#include "Services/TodoService.h"

class TodoServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        // This will run before each test
        service.clear();  // Ensure clean state
    }

    TodoService service;
};

TEST_F(TodoServiceTest, AddsTodoCorrectly) {
    service.addTodo("Write tests", 0);
    auto table = service.getTodoTable(0);

    ASSERT_EQ(table.size(), 2);  // 1 header + 1 entry
    EXPECT_EQ(table[1][2], "Write tests");
    EXPECT_EQ(table[1][1], "MEDIUM");
    EXPECT_EQ(table[1][3], "❌");  // Not completed
}

TEST_F(TodoServiceTest, DeletesTodoCorrectly) {
    service.addTodo("A", 0);
    service.addTodo("B", 0);

    service.deleteTodo(0, 0);

    auto table = service.getTodoTable(0);
    ASSERT_EQ(table.size(), 2);  // header + 1 entry left
    EXPECT_EQ(table[1][2], "B");
}

TEST_F(TodoServiceTest, ChecksAndUnchecksTodo) {
    service.addTodo("Task", 0);

    service.checkTodo(0, 0);
    EXPECT_EQ(service.getTodoTable(0)[1][3], "✅");

    service.uncheckTodo(0, 0);
    EXPECT_EQ(service.getTodoTable(0)[1][3], "❌");
}

TEST_F(TodoServiceTest, SetsPriorityCorrectly) {
    service.addTodo("Task", 0);
    service.setPrio(0, 0, Priority::HIGH);
    EXPECT_EQ(service.getTodoTable(0)[1][1], "HIGH");

    service.setPrio(0, 0, Priority::LOW);
    EXPECT_EQ(service.getTodoTable(0)[1][1], "LOW");
}

TEST_F(TodoServiceTest, ClearsAllTodos) {
    service.addTodo("X", 0);
    service.addTodo("Y", 1);

    service.clear();
    EXPECT_EQ(service.getTodoTable(0).size(), 1);  // header only
    EXPECT_EQ(service.getTodoTable(1).size(), 1);
}
