//
// Created by philipp on 22.05.25.
//

#include "HelpRenderer.h"

#include "ServiceContainer.h"
#include "DTO/WindowState.h"

HelpRenderer::HelpRenderer(ScreenInteractive &screen) : screen(screen) {
    auto component = Container::Stacked({
            // tabToggle,
            // todoInput,
        });

    renderer = Renderer(component , [&] { return refreshWindow(); });
    renderer |= CatchEvent([&] (const Event &e) { return handleRendererEvent(e); });
}

Component HelpRenderer::getRenderer() {
    return renderer;
}

Element HelpRenderer::refreshWindow() {
    if (ServiceContainer::windowStateHandler->shouldSwitchWindow()) {
        screen.Exit();
    }

    return window(text("TODO-Board | Help"), vbox({
        hbox(paragraph(helpText)),
    }));
}

bool HelpRenderer::handleRendererEvent(const Event &event) {
    if (event == Event::Character('q')) {
        ServiceContainer::windowStateHandler->switchWindow(WindowState::TODO);

        return true;
    }

    return false;
}
