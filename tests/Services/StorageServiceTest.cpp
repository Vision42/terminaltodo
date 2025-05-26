//
// Created by philipp on 26.05.25.
//

#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
#include "Services/StorageService.h"
#include "DTO/TodoContainer.h"
#include "DTO/TODOElement.h"

class StorageServiceTest : public ::testing::Test {
protected:
    std::string testDir = "/tmp/todo_test";
    std::string testFile;

    void SetUp() override {
        std::filesystem::create_directories(testDir);
        setenv("HOME", testDir.c_str(), 1);

        std::cout << testDir << std::endl;
        testFile = StorageService::getApplicationDirectory() + "todo.dat";
    }

    void TearDown() override {
        std::filesystem::remove_all(testDir);
    }
};

TEST_F(StorageServiceTest, StoresAndLoadsDataCorrectly) {
    StorageService service;

    std::vector<TodoContainer> original(1);
    TODOElement elem;
    elem.content = "Test Task";
    elem.priority = "HIGH";
    elem.completed = true;
    original[0].elements.push_back(elem);

    service.storeData(original);

    std::vector<TodoContainer> loaded;
    service.loadData(loaded);

    ASSERT_EQ(loaded.size(), original.size());
    ASSERT_EQ(loaded[0].elements.size(), original[0].elements.size());
    EXPECT_EQ(loaded[0].elements[0].content, "Test Task");
    EXPECT_EQ(loaded[0].elements[0].priority, "HIGH");
    EXPECT_TRUE(loaded[0].elements[0].completed);
}