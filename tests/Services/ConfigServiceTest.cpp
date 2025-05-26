//
// Created by philipp on 26.05.25.
//

#include <filesystem>
#include <gtest/gtest.h>

#include "Services/StorageService.h"

class ConfigServiceTest : public ::testing::Test {
    std::string testDir = "/tmp/todo_test";

    void SetUp() override {
        std::filesystem::create_directories(testDir);
        setenv("HOME", testDir.c_str(), 1);
    }

    void TearDown() override {
        std::filesystem::remove_all(testDir);
    }
};

TEST_F(ConfigServiceTest, StoreAndLoadIniSettings) {
    StorageService storageService;
    ConfigService configService;

    configService.writeValue("TEST_SECTION", "TEST_KEY", "value1");

    ASSERT_TRUE(std::filesystem::exists("/tmp/todo_test/opt/terminaltodo/config.ini"));
    ASSERT_EQ("value1", configService.getValue("TEST_SECTION", "TEST_KEY", "other_stuff"));
}

TEST_F(ConfigServiceTest, DefaultValues) {
    StorageService storageService;
    ConfigService configService;

    ASSERT_EQ("default_value", configService.getValue("TEST_SECTION", "TEST_KEY", "default_value"));
}