//
// Created by philipp on 27.05.25.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    static void initialize();

private:
    static void createFolders();
};



#endif //LOGGER_H
