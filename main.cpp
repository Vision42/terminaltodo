#include <iostream>
#include "MainWindow.h"
#include "ServiceContainer.h"

int main() {
    ServiceContainer::initialize();

    auto window = MainWindow();
    window.show();

    return 0;
}