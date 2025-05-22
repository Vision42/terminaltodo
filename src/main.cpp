#include "UI/MainWindow.h"
#include "ServiceContainer.h"

int main() {
    ServiceContainer::initialize();
    ServiceContainer::todoService->load();

    auto window = MainWindow();
    window.show();

    return 0;
}