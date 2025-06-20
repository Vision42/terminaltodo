//
// Created by philipp on 22.05.25.
//

#include "StorageService.h"
#include "Exceptions/IOException.h"

StorageService::StorageService() {
    if (! std::filesystem::is_directory(getApplicationDirectory())) {
        std::filesystem::create_directories(getApplicationDirectory());
    }
}

/**
 * @throws IOException
 */
void StorageService::storeData(const std::vector<TodoContainer> &todoContainers) const {
    std::ofstream file(getApplicationDirectory() + fileName, std::ios::binary);

    if (! file.is_open()) {
        throw IOException("Failed to open file " + getApplicationDirectory() + fileName);
    }

    size_t size = todoContainers.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& container: todoContainers) {
        size_t elementSize = container.elements.size();
        file.write(reinterpret_cast<const char*>(&elementSize), sizeof(elementSize));

        for (const auto &element: container.elements) {
            element.serialize(file);
        }
    }

    file.close();
}

void StorageService::loadData(std::vector<TodoContainer> &todoContainers) const {
    std::ifstream file(getApplicationDirectory() + fileName, std::ios::binary);

    if (! file.is_open()) {
        throw IOException("Failed to load file " + getApplicationDirectory() + fileName);
    }

    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    todoContainers.resize(size);

    for (size_t i = 0; i < size; i++) {
        TodoContainer container;

        size_t elementSize;
        file.read(reinterpret_cast<char*>(&elementSize), sizeof(elementSize));
        container.elements.resize(elementSize);

        for (auto& element : container.elements) {
            element.deserialize(file);
        }

        todoContainers[i] = container;
    }

    file.close();
}

std::string StorageService::getApplicationDirectory() {
#ifdef _WIN32
    const char* homeDir = std::getenv("USERPROFILE");
#else
    const char* homeDir = std::getenv("HOME");
#endif

    //TODO: Exception handling

    return (homeDir ? std::string(homeDir) + "/opt/terminaltodo/" : "");
}
