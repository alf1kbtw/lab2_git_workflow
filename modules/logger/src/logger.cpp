#include "logger.h"
#include <iostream>
#include <fstream>


static std::ofstream log_file;

void log_init(const std::string& filename) {
    if (!filename.empty()) {
        if (log_file.is_open()) {
            log_file.close();
        }
        log_file.open(filename, std::ios::app);
    }
}

void log_message(LogLevel level, const std::string& message) {
    std::string level_str;

    switch (level) {
        case LogLevel::INFO:  level_str = "[INFO]"; break;
        case LogLevel::ERROR: level_str = "[ERROR]"; break;
    }


    std::string full_message = level_str + " " + message;

    if (log_file.is_open()) {
        log_file << full_message << std::endl;
    } else {
        if (level == LogLevel::ERROR) {
            std::cerr << full_message << std::endl;
        } else {
            std::cout << full_message << std::endl;
        }
    }
}