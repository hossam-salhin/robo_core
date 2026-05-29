#pragma once

#include  <iostream>
#include <fstream>
#include <ctime>
#include "logLevel.h"
#include <sstream>
#include <filesystem>
namespace fs = std::filesystem;


class Logger   //singltone class that has only one instance
{
    public:
    static Logger& getInstance();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void log(logLevel level, const std::string& message);

    private:
    logLevel minLevel = logLevel::INFO;
    std::ofstream logFile;

    Logger()
    {   std::string log_dir = "../logs";
        fs::create_directories(log_dir);

        time_t now = time(nullptr);
        std::tm* local_time = std::localtime(&now);

        char time_str[20];
        std::strftime(time_str, sizeof(time_str), "%Y-%m-%d_%H-%M-%S", local_time);

        std::ostringstream filename;
        filename << log_dir << "/log_" <<time_str <<".txt";

        logFile.open(filename.str(), std::ios::app );
        
        if (!logFile.is_open()) 
        {
            std::cerr << "Logger Error: Could not open file " << filename.str() 
                      << ". Ensure 'logs/' directory exists." << std::endl;
        }
    }

    std::string getLevelStr(logLevel level) const
    {
        switch (level)
        {
        case logLevel::INFO: return "[INFO]";
        case logLevel::WARNING: return "[WARNING]";
        case logLevel::ERROR: return "[ERROR]";
        default:              return "[UNKNOWN]";
        }
    }
};

