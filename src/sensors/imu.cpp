#include "sensors/imu.h"
#include <iostream>


Imu::Imu(const std::string& name): Sensor(name)
{
    std::cout << "an imu created with initail value 0.0\n";
    
}

void Imu::update()
{
    

    accel.x = dist(gen);
    accel.y = dist(gen);
    accel.z = dist(gen);

    gyro.x = gyr(gen);
    gyro.y = gyr(gen);
    gyro.z = gyr(gen);
    std::cout << "imu updated!\n";
}

void Imu::display() const
{
    std::cout << "Sensor Name: " << this->getName() << "[ID: " << this->getID() << "] readings: \n";
    std::cout << "acceleration reading: "<< accel << "}\n";
    std::cout << "Gyro reading: " << gyro << "\n\n";


}

