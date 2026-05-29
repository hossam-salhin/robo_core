#include <iostream>
#include "sensors/lidar.h"

Lidar::Lidar(const std::string& name, const uint16_t p_range) :Sensor(name), range(p_range)
{
    lidar_readings.resize(range);
    Logger::getInstance().log(logLevel::INFO, "Lidar [" + this->getName() + "] created");
}

void Lidar::update()
{
    for(auto& lidar_point: lidar_readings)
    {
        lidar_point.x = point(gen);
        lidar_point.y = point(gen);
        lidar_point.z = point(gen);
    }
    Logger::getInstance().log(logLevel::INFO, "Lidar [" + this->getName() + "] updated");
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



