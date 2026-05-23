#include <iostream>
#include "sensors/lidar.h"

Lidar::Lidar(const std::string& name, const uint16_t p_range) :Sensor(name), range(p_range)
{
    lidar_readings.resize(range);
    std::cout << "lidar sensor is created!\n";
}

void Lidar::update()
{
    for(auto& lidar_point: lidar_readings)
    {
        lidar_point.x = point(gen);
        lidar_point.y = point(gen);
        lidar_point.z = point(gen);
    }
    std::cout << "Lidar updated\n";
}

void Lidar::display() const
{

    std::cout << "Sensor Name: "  <<  this->getName() << "[ID: " << this->getID() << "] readings: \n";
    for(const auto& item: lidar_readings)
    {
        std::cout << item << ", ";
    }
    std::cout << "\n\n";
}



