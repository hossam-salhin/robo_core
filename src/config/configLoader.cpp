#include "config/configLoader.h"
#include <fstream>
#include "logging/logger.h"


void ConfigLoader::load(const std::string &filePath)
{
    std::ifstream file(filePath);
    std::string line;

    if(!file.is_open())
    {
        Logger::getInstance().log(logLevel::ERROR, "ConfigLoad: failed to openfile " + filePath);
        return ;
    }
    while(std::getline(file,line))
    {
        if(line.empty()) continue;
        if(line[0] == '#') continue;
        if(line.find('=') == std::string::npos) continue;

        size_t pos = line.find('=');
        std::string key = trim(line.substr(0,pos));
        std::string value = trim(line.substr(pos + 1));
        data[key] = value;
    }
}

std::string ConfigLoader::getString(const std::string &key, const std::string &defaultVal)
{
    auto it = data.find(key);

    if(it != data.end())
    {
        return it->second;
    }
    Logger::getInstance().log(logLevel::WARNING, "Config key not found '" + key + "' using default");
    return defaultVal;
}

int ConfigLoader::getInt(const std::string &key, int defaultVal)
{
    auto it = data.find(key);

    if(it != data.end())
    {
        return std::stoi(it->second);
    }
    Logger::getInstance().log(logLevel::WARNING, "Config key not found '" + key + "' using default");
    return defaultVal;
}

float ConfigLoader::getFloat(const std::string &key, float defaultVal)
{
    auto it = data.find(key);

    if(it != data.end())
    {
        return std::stof(it->second);
    }
    
    Logger::getInstance().log(logLevel::WARNING, "Config key not found '" + key + "' using default");
    return defaultVal;
    
}


