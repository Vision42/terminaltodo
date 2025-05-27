//
// Created by philipp on 27.05.25.
//

#include "Logger.h"

#include <filesystem>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/expressions.hpp>

#include "Services/StorageService.h"

void Logger::initialize() {
    using namespace boost::log;

    createFolders();

    add_file_log(
        keywords::file_name = StorageService::getApplicationDirectory() + "log/log_%N.log",
        keywords::rotation_size = 10 * 1024 * 1024,
        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
        keywords::auto_flush = true,
        keywords::format = "[%TimeStamp%] [%Severity%]: %Message%"
    );

    add_common_attributes();

    BOOST_LOG_TRIVIAL(info) << "Logger initialized";
}

void Logger::createFolders() {
    std::filesystem::create_directory(StorageService::getApplicationDirectory()  + "log");
}
