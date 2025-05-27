#include "UI/MainWindow.h"
#include "ServiceContainer.h"
#include "DTO/WindowState.h"
#include "Logger.h"

int main() {
    Logger::initialize();
    ServiceContainer::initialize();
    ServiceContainer::todoService->load();

    auto window = MainWindow();
    window.show(WindowState::TODO);

    return 0;
}
