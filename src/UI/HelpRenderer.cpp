//
// Created by philipp on 22.05.25.
//

#include "HelpRenderer.h"

#include "ServiceContainer.h"

HelpRenderer::HelpRenderer(ScreenInteractive &screen) : screen(screen) {
    auto component = Container::Stacked({
            // tabToggle,
            // todoInput,
        });

    renderer = Renderer(component , [&] {return refreshWindow();});
}

Component HelpRenderer::getRenderer() {
    return renderer;
}

Element HelpRenderer::refreshWindow() {
    if (ServiceContainer::windowStateHandler->shouldSwitchWindow()) {
        screen.Exit();
    }

    return window(text("TODO-Board | Help"), vbox({
        separator(),
    }));
}
