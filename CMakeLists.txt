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
FetchContent_MakeAvailable(ftxui)

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