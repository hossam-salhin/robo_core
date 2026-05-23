#include "sensors/imu.h"
#include "sensors/lidar.h"
#include "sensors/sensorRegistry.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>



int main()
{
    SensorRegistry registry;

    registry.addSensor(std::make_unique<Imu>("base_imu"));
    registry.addSensor(std::make_unique<Lidar>("lidar3D", 10));


    for(size_t i = 0 ; i < 2; ++i)
    {
        registry.updateAll();
        registry.displayAll();

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    std::cin.get();
    return 0;
}