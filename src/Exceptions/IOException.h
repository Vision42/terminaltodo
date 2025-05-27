//
// Created by philipp on 27.05.25.
//

#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <exception>

class IOException : public std::exception {
public:
    explicit IOException(const std::string& message) : message(message) {};

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};



#endif //IOEXCEPTION_H
