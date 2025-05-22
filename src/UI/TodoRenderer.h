//
// Created by philipp on 22.05.25.
//

#ifndef TODORENDERER_H
#define TODORENDERER_H

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <string>

#include "ftxui/component/component.hpp"
#include "ServiceContainer.h"
#include "Services/CommandProcessor.h"

using namespace ftxui;

class TodoRenderer {
public:
    TodoRenderer() = delete;
    TodoRenderer(ScreenInteractive &screen);

    Component getRenderer();

private:
    Component renderer;
    ScreenInteractive &screen;

    std::string textInput;
    int daySelected = 0;
    std::vector<std::string> tabValues{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    Component todoInput = Input(&textInput, "TODO");
    Component tabToggle = Toggle(&tabValues, &daySelected);

    Table buildTable();
    Element refreshWindow();
    bool handleTodoInputEvent(const Event &event);
    bool handleTabInputEvent(const Event &event);
};



#endif //TODORENDERER_H
