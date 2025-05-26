//
// Created by philipp on 22.05.25.
//

#ifndef WINDOWSTATEHANDLER_H
#define WINDOWSTATEHANDLER_H

#include "Interfaces/IWindowStateHandler.h"

class WindowStateHandler : public IWindowStateHandler {
public:
    WindowStateHandler();
    void switchWindow(int targetWindow) override;
    void setActiveWindow(int window) override;
    bool shouldSwitchWindow() override;
    int getTargetWindow() override;

private:
    int currentWindow;
    int targetWindow;
};



#endif //WINDOWSTATEHANDLER_H
