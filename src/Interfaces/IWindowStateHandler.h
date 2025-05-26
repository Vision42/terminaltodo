//
// Created by philipp on 26.05.25.
//

#ifndef IWINDOWSTATEHANDLER_H
#define IWINDOWSTATEHANDLER_H

class IWindowStateHandler {
public:
    virtual void switchWindow(int targetWindow) = 0;
    virtual void setActiveWindow(int window) = 0;
    virtual bool shouldSwitchWindow() = 0;
    virtual int getTargetWindow() = 0;

    virtual ~IWindowStateHandler() = default;
};

#endif //IWINDOWSTATEHANDLER_H
