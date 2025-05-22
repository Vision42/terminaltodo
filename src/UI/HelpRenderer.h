//
// Created by philipp on 22.05.25.
//

#ifndef HELPRENDERER_H
#define HELPRENDERER_H

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <string>

#include "ftxui/component/component.hpp"

using namespace ftxui;

class HelpRenderer {
public:
    HelpRenderer() = delete;
    HelpRenderer(ScreenInteractive &screen);

    Component getRenderer();

private:
    ScreenInteractive &screen;
    Component renderer;

    std::string helpText = "Commands:\n"
                           ":check [ID] -> Checks an todolist entry\n"
                           ":uncheck [ID] -> Unchecks an todolist entry\n"
                           ":delete [ID] -> Deletes an todolist entry\n"
                           ":prio [ID] [Level 0 - 3] -> Sets the priority of an todolist entry\n"
                           ":save -> Saves the current todolist to disk\n"
                           ":help -> Opens this help page\n"
                           "\n"
                           "Leave this page with 'q'";

    Element refreshWindow();
    bool handleRendererEvent(const Event &event);
};



#endif //HELPRENDERER_H
