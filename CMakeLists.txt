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
        src/Services/AudioService.h
        src/Interfaces/ITodoService.h
        src/Interfaces/IWindowStateHandler.h
        src/Interfaces/IConfigService.h
        src/Services/ConfigService.cpp
        src/Services/ConfigService.h
        src/Logger.cpp
        src/Logger.h)
target_include_directories(todo-lib PUBLIC src)

include(FetchContent)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v6.1.9
)
FetchContent_Declare(
        simpleini
        GIT_REPOSITORY https://github.com/brofield/simpleini.git
        GIT_TAG v4.22
)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(ftxui)
FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(simpleini)

target_sources(todo-lib PRIVATE ${simpleini_SOURCE_DIR}/ConvertUTF.c)
target_include_directories(todo-lib PUBLIC ${simpleini_SOURCE_DIR})

find_package(SFML 2.5 COMPONENTS audio REQUIRED)
find_package(Boost REQUIRED COMPONENTS log log_setup thread filesystem system)

target_link_libraries(todo-lib PUBLIC
        # Chose a submodule
        ftxui::component
        ftxui::dom
        ftxui::screen

        sfml-audio

        Boost::log
        Boost::log_setup
        Boost::thread
        Boost::filesystem
        Boost::system
)

add_executable(todo src/main.cpp)
target_link_libraries(todo todo-lib)
add_dependencies(todo todo-lib)

##Testing

enable_testing()
add_executable(todo-test
        tests/ServiceContainerTest.cpp
        tests/Services/TodoServiceTest.cpp
        tests/Services/FormatterTest.cpp
        tests/Services/PomodoroServiceTest.cpp
        tests/Services/CommandProcessorTest.cpp
        tests/Services/StorageServiceTest.cpp
        tests/Services/WindowStateHandlerTest.cpp
        tests/Services/ConfigServiceTest.cpp
)

target_link_libraries(todo-test GTest::gtest_main GTest::gmock_main todo-lib)

include(GoogleTest)
gtest_discover_tests(todo-test)

##CPACK

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "TerminalTODO")
set(CPACK_PACKAGE_VERSION "0.1.0")
set(CPACK_PACKAGE_CONTACT "p.limmer@limmer-laboratories.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Philipp Limmer")
set(CPACK_PACKAGE_DESCRIPTION "A simple terminal todo application")
set(CPACK_GENERATOR "DEB")

include(CPack)

install(TARGETS todo DESTINATION bin)
install(FILES res/timeup.ogg DESTINATION ~/opt/terminaltodo)
install(FILES res/config.ini DESTINATION ~/opt/terminaltodo)