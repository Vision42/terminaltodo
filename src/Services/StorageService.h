//
// Created by philipp on 22.05.25.
//

#ifndef STORAGESERVICE_H
#define STORAGESERVICE_H

#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>

#include "ServiceContainer.h"

class StorageService {
public:
    StorageService();
    void storeData(std::vector<TodoContainer> &todoContainers);
    void loadData(std::vector<TodoContainer> &todoContainers);
    static std::string getApplicationDirectory();

private:
    const std::string fileName{"store"};
};



#endif //STORAGESERVICE_H
