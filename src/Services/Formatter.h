//
// Created by philipp on 23.05.25.
//

#ifndef FORMATTER_H
#define FORMATTER_H

#include <chrono>
#include <string>
#include <sstream>

class Formatter {
public:
    static std::string formatMicroseconds(std::chrono::microseconds microseconds);
};



#endif //FORMATTER_H
