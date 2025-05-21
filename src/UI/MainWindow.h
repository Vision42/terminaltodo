//
// Created by philipp on 21.05.25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <string>

#include "ftxui/component/component.hpp"
#include "ServiceContainer.h"
#include "Services/TodoService.h"


class MainWindow {
public:
    MainWindow();
    void show();

private:
    ftxui::Component renderer;
    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();

    std::string textInput;
    int daySelected = 0;
    std::vector<std::string> tabValues{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    ftxui::Component todoInput = ftxui::Input(&textInput, "TODO");
    ftxui::Component tabToggle = ftxui::Toggle(&tabValues, &daySelected);

    ftxui::Table buildTable();
    ftxui::Element refreshWindow();
    bool handleTodoInputEvent(const ftxui::Event &event);
    bool handleTabInputEvent(const ftxui::Event &event);
};



#endif //MAINWINDOW_H
