//
// Created by philipp on 22.05.25.
//

#include "TodoRenderer.h"

TodoRenderer::TodoRenderer(ScreenInteractive &screen) : screen(screen) {
    todoInput |= CatchEvent([&] (const Event &e) { return handleTodoInputEvent(e); });
    tabToggle |= CatchEvent([&] (const Event &e) { return handleTabInputEvent(e); });

    auto component = Container::Stacked({
        tabToggle,
        todoInput,
    });

    renderer = Renderer(component , [&] {return refreshWindow();});
}

Component TodoRenderer::getRenderer() {
    return renderer;
}

Table TodoRenderer::buildTable() {
    auto tableData = ServiceContainer::todoService->getTodoTable(daySelected);

    auto table = Table(tableData);
    table.SelectRow(0).Decorate(bold);
    table.SelectRow(0).SeparatorVertical(LIGHT);
    table.SelectRow(0).Border(DOUBLE);
    table.SelectColumn(3).DecorateCells(align_right);

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

    auto terminal_width = Terminal::Size().dimx;
    auto column_count = tableData[0].size();
    auto col_width = terminal_width / column_count;

    for (int col = 0; col < column_count; ++col) {
        table.SelectColumn(col).DecorateCells(size(WIDTH, EQUAL, col_width));
    }

    return table;
}

Element TodoRenderer::refreshWindow() {
    auto table = buildTable();

    if (ServiceContainer::windowStateHandler->shouldSwitchWindow()) {
        screen.Exit();
    }

    return window(text("TODO-Board"), vbox({
        tabToggle->Render(),
        separator(),
        hbox(table.Render())| flex,
        hbox(text("Todo: "), todoInput->Render()),
    }));
}

bool TodoRenderer::handleTodoInputEvent(const Event &event) {
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

bool TodoRenderer::handleTabInputEvent(const Event &event) {
    if (event == Event::Return) {
        todoInput->TakeFocus();
        screen.PostEvent(Event::Custom);

        return true;
    }

    return false;
}
