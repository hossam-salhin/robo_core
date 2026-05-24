#include "logging/logger.h"



Logger &Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::log(logLevel level, const std::string& message)
{
    if(level < minLevel) return;

    if(logFile.is_open())
    {

        time_t now = time(nullptr);
        std::tm* local_tm = std::localtime(&now);
        char timeStr[10];
        std::strftime(timeStr,sizeof(timeStr),"%H:%M:%S", local_tm);

        logFile << getLevelStr(level) << " " << timeStr << " - " << message << std::endl;
        std::cout << getLevelStr(level) << " " << timeStr << " - " << message << std::endl;
    }
}