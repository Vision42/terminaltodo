//
// Created by philipp on 22.05.25.
//

#ifndef WINDOWSTATEHANDLER_H
#define WINDOWSTATEHANDLER_H



class WindowStateHandler {
public:
    WindowStateHandler();
    void switchWindow(int targetWindow);
    void setActiveWindow(int window);
    bool shouldSwitchWindow();
    int getTargetWindow();

private:
    int currentWindow;
    int targetWindow;
};



#endif //WINDOWSTATEHANDLER_H
