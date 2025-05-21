//
// Created by philipp on 21.05.25.
//

#include "MainWindow.h"

#include "ftxui/component/component_base.hpp"
#include "Services/CommandProcessor.h"

using namespace ftxui;

MainWindow::MainWindow() {
    todoInput |= CatchEvent([&] (const Event &e) { return handleTodoInputEvent(e); });

    auto component = Container::Stacked({
        tabToggle,
        todoInput,
    });

    renderer = Renderer(component , [&] {return refreshWindow();});
}

void MainWindow::show() {
    todoInput->TakeFocus();
    screen.Loop(renderer);
}

Table MainWindow::buildTable() {
    auto table = Table(ServiceContainer::todoService->getTodoTable(daySelected));
    table.SelectRow(0).Decorate(bold);
    table.SelectRow(0).SeparatorVertical(LIGHT);
    table.SelectRow(0).Border(DOUBLE);
    table.SelectColumn(2).DecorateCells(align_right);

    auto content = table.SelectRows(1, -1);
    // Alternate in between 3 colors.
    content.DecorateCellsAlternateRow(color(Color::Blue), 3, 0);
    content.DecorateCellsAlternateRow(color(Color::Cyan), 3, 1);
    content.DecorateCellsAlternateRow(color(Color::White), 3, 2);

    return table;
}

Element MainWindow::refreshWindow() {
    auto table = buildTable();

    return window(text("TODO-Board"), vbox({
        tabToggle->Render(),
        separator(),
        hbox(table.Render())| flex,
        hbox(text("Todo: "), todoInput->Render()),
    }));
}

bool MainWindow::handleTodoInputEvent(const Event &event) {
    if (event == Event::Return) {
        CommandProcessor commandProcessor{textInput, daySelected};

        if (! commandProcessor.isCommand()) {
            ServiceContainer::todoService->addTodo(textInput, daySelected);
        } else {
            commandProcessor.processCommand();
        }

        textInput.clear();
        screen.PostEvent(Event::Custom);

        return true;
    }

    return false;
}
