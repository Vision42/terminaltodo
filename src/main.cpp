#include "UI/MainWindow.h"
#include "ServiceContainer.h"
#include "DTO/WindowState.h"

int main() {
    ServiceContainer::initialize();
    ServiceContainer::todoService->load();

    auto window = MainWindow();
    window.show(WindowState::TODO);

    return 0;
}
