//
// Created by philipp on 26.05.25.
//

#ifndef CONFIGSERVICE_H
#define CONFIGSERVICE_H
#include <string>
#include <SimpleIni.h>

#include "Interfaces/IConfigService.h"


class ConfigService : public IConfigService {
public:
    ConfigService();
    std::string getValue(std::string section, std::string key, std::string def) override;
    void writeValue(std::string section, std::string key, std::string value) override;

private:
    const std::string configFile = "config.ini";

    CSimpleIniA config;
};



#endif //CONFIGSERVICE_H
