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


class MainWindow {
public:
    MainWindow();
    void show(int window);

private:
    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();
};



#endif //MAINWINDOW_H
