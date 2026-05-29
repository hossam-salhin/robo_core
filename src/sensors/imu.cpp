#include "sensors/imu.h"
#include <iostream>


Imu::Imu(const std::string& name): Sensor(name)
{
    Logger::getInstance().log(logLevel::INFO,  "imu [" + this->getName() + "] created");
}

void Imu::update()
{
    accel.x = dist(gen);
    accel.y = dist(gen);
    accel.z = dist(gen);

    gyro.x = gyr(gen);
    gyro.y = gyr(gen);
    gyro.z = gyr(gen);
    Logger::getInstance().log(logLevel::INFO, "imu [" + this->getName() + "] updated");
}

void Imu::display() const
{
    std::cout << "Sensor Name: " << this->getName() << "[ID: " << this->getID() << "] readings: \n";
    std::cout << "acceleration reading: "<< accel << "\n";
    std::cout << "Gyro reading: " << gyro << "\n\n";
}

