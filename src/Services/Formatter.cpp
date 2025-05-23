//
// Created by philipp on 23.05.25.
//

#include "Formatter.h"

#include <iomanip>

std::string Formatter::formatMicroseconds(std::chrono::microseconds microseconds) {
    auto totalSeconds = duration_cast<std::chrono::seconds>(microseconds);
    auto minutes = duration_cast<std::chrono::minutes>(totalSeconds);
    auto seconds = totalSeconds - minutes;

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << minutes.count() << ":"
    << std::setw(2) << std::setfill('0') << seconds.count();

    return oss.str();
}
