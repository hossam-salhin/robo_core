#pragma once
#include <string>
#include <unordered_map>

class ConfigLoader
{
    private:
    std::unordered_map<std::string, std::string> data;

    std::string trim(const std::string& str)
    {
        size_t start = str.find_first_not_of(" \t\r\n");
        size_t end = str.find_last_not_of(" \t\r\n");
        if(start == std::string::npos) return "";
        return str.substr(start, end - start +1);
    }

    public:
    void load(const std::string& path);
    std::string getString(const std::string& key, const std::string& defaultVal);
    int getInt(const std::string& key, int defaultVal);
    float getFloat(const std::string& key, float defaultVal);
};