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

    ftxui::Component todoInput = ftxui::Input(&textInput, "TODO");

    ftxui::Table buildTable();
    ftxui::Element refreshWindow();
    bool handleTodoInputEvent(const ftxui::Event &event);
};



#endif //MAINWINDOW_H
