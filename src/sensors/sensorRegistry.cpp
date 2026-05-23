#include "sensors/sensorRegistry.h"

void SensorRegistry::addSensor(std::unique_ptr<Sensor> sensor)
{
    sensors.push_back(std::move(sensor));
}

void SensorRegistry::updateAll()
{
    for(const auto& item: sensors)
    {
        item->update();
    }
}

void SensorRegistry::displayAll() const
{
    for(const auto& item: sensors)
    {
        item->display();
    }
}

