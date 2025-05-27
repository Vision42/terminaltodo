//
// Created by philipp on 26.05.25.
//

#include "ConfigService.h"
#include "StorageService.h"
#include "Exceptions/IOException.h"

ConfigService::ConfigService() {
    config.SetUnicode();
    config.LoadFile((StorageService::getApplicationDirectory() + configFile).c_str());
}

std::string ConfigService::getValue(const std::string section, const std::string key, const std::string def) {
    return config.GetValue(section.c_str(), key.c_str(), def.c_str());
}

void ConfigService::writeValue(const std::string section, const std::string key, const std::string value) {
    config.SetValue(section.c_str(), key.c_str(), value.c_str());

    auto result = config.SaveFile((StorageService::getApplicationDirectory() + configFile).c_str());
    if (result < 0) {
        throw IOException("Error writing config file. Code: " + result);
    }
}
