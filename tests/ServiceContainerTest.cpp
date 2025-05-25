//
// Created by philipp on 25.05.25.
//
#include <gtest/gtest.h>
#include "ServiceContainer.h"

TEST(ServiceContainer, ServicesLoaded) {
    ServiceContainer::initialize();

    ASSERT_NE(ServiceContainer::pomodoroService, nullptr);
    ASSERT_NE(ServiceContainer::audioService, nullptr);
    ASSERT_NE(ServiceContainer::todoService, nullptr);
    ASSERT_NE(ServiceContainer::windowStateHandler, nullptr);
}