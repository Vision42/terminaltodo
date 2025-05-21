cmake_minimum_required(VERSION 3.31)
project(todo)
set(CMAKE_CXX_STANDARD 23)

add_library(todo-lib
        MainWindow.cpp
        MainWindow.h
        TODOElement.h
        TodoService.cpp
        TodoService.h
        ServiceContainer.cpp
        ServiceContainer.h)

include(FetchContent)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

target_link_libraries(todo-lib PUBLIC
        # Chose a submodule
        ftxui::component
        ftxui::dom
        ftxui::screen
)

add_executable(todo main.cpp)
target_link_libraries(todo todo-lib)
add_dependencies(todo todo-lib)
