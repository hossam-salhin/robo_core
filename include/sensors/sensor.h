#pragma once

#include <string>
#include "logging/logger.h"


class Sensor
{
    public:
    Sensor(const std::string& s_name): Name(s_name)
    {
        counter++;
        Id = counter;
    }

    virtual void update() = 0;
    virtual void display() const = 0;


    const std::string& getName() const
    {
        return this->Name;
    }

    int getID() const
    {
        return this->Id;
    }
    virtual ~Sensor() = default;

    
    private:
    std::string Name;
    int Id;
    inline static int counter = 0;
};

