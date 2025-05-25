cmake_minimum_required(VERSION 3.31)
project(todo)
set(CMAKE_CXX_STANDARD 23)

add_library(todo-lib
        src/UI/MainWindow.cpp
        src/UI/MainWindow.h
        src/DTO/TODOElement.h
        src/Services/TodoService.cpp
        src/Services/TodoService.h
        src/ServiceContainer.cpp
        src/ServiceContainer.h
        src/Services/CommandProcessor.cpp
        src/Services/CommandProcessor.h
        src/DTO/TodoContainer.h
        src/DTO/Priority.h
        src/Services/StorageService.cpp
        src/Services/StorageService.h
        src/Interfaces/ISerializable.h
        src/UI/TodoRenderer.cpp
        src/UI/TodoRenderer.h
        src/DTO/WindowState.h
        src/Services/WindowStateHandler.cpp
        src/Services/WindowStateHandler.h
        src/UI/HelpRenderer.cpp
        src/UI/HelpRenderer.h
        src/UI/PomodoroRenderer.cpp
        src/UI/PomodoroRenderer.h
        src/UI/Renderer.h
        src/Services/PomodoroService.cpp
        src/Services/PomodoroService.h
        src/Services/TimedScreenRefresher.cpp
        src/Services/TimedScreenRefresher.h
        src/Services/Formatter.cpp
        src/Services/Formatter.h
        src/DTO/PomodoroPhases.h
        src/Services/AudioService.cpp
        src/Services/AudioService.h)
target_include_directories(todo-lib PUBLIC src)

include(FetchContent)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v6.1.9
)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(ftxui)
FetchContent_MakeAvailable(googletest)

find_package(SFML 2.5 COMPONENTS audio REQUIRED)
target_link_libraries(todo-lib PUBLIC
        # Chose a submodule
        ftxui::component
        ftxui::dom
        ftxui::screen
        sfml-audio
)

add_executable(todo src/main.cpp)
target_link_libraries(todo todo-lib)
add_dependencies(todo todo-lib)

enable_testing()
add_executable(todo-test
        tests/ServiceContainerTest.cpp
        tests/Services/TodoServiceTest.cpp
)

target_link_libraries(todo-test GTest::gtest_main GTest::gmock_main todo-lib)

include(GoogleTest)
gtest_discover_tests(todo-test)