#pragma once 
#include "sensor.h"
#include <vector>
#include <memory>



class SensorRegistry 
{
    public:
    void addSensor(std::unique_ptr<Sensor> sensor);
    void updateAll();
    void displayAll() const;

    private:
    std::vector<std::unique_ptr<Sensor>> sensors; 
};

