//
// Created by philipp on 21.05.25.
//

#include "MainWindow.h"

#include "ftxui/component/component_base.hpp"
#include "Services/CommandProcessor.h"

using namespace ftxui;

MainWindow::MainWindow() {
    todoInput |= CatchEvent([&] (const Event &e) { return handleTodoInputEvent(e); });
    tabToggle |= CatchEvent([&] (const Event &e) { return handleTabInputEvent(e); });

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
    auto tableData = ServiceContainer::todoService->getTodoTable(daySelected);

    auto table = Table(tableData);
    table.SelectRow(0).Decorate(bold);
    table.SelectRow(0).SeparatorVertical(LIGHT);
    table.SelectRow(0).Border(DOUBLE);
    table.SelectColumn(2).DecorateCells(align_right);

    auto content = table.SelectRows(1, -1);
    // Alternate in between 3 colors.
    content.DecorateCellsAlternateRow(color(Color::Blue), 3, 0);
    content.DecorateCellsAlternateRow(color(Color::Cyan), 3, 1);
    content.DecorateCellsAlternateRow(color(Color::White), 3, 2);

    for (size_t i = 0; i < tableData.size(); i++) {
        if (tableData[i][1] == "HIGH") {
            table.SelectRow(static_cast<int>(i)).Decorate(bgcolor(Color::Red1));
        }
    }

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

    if (event == Event::Tab) {
        tabToggle->TakeFocus();

        return true;
    }

    return false;
}

bool MainWindow::handleTabInputEvent(const Event &event) {
    if (event == Event::Return) {
        todoInput->TakeFocus();
        screen.PostEvent(Event::Custom);

        return true;
    }

    return false;
}
