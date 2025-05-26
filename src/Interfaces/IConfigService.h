//
// Created by philipp on 26.05.25.
//

#ifndef ICONFIGSERVICE_H
#define ICONFIGSERVICE_H

#include <string>

class IConfigService {
public:
    virtual std::string getValue(std::string section, std::string key, std::string def) = 0;
    virtual void writeValue(std::string section, std::string key, std::string value) = 0;

    virtual ~IConfigService() = default;
};

#endif //ICONFIGSERVICE_H
