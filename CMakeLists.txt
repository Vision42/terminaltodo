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
        src/Services/CommandProcessor.h)
target_include_directories(todo-lib PUBLIC src)

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

add_executable(todo src/main.cpp)
target_link_libraries(todo todo-lib)
add_dependencies(todo todo-lib)
