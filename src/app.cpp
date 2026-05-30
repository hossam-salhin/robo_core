#include "sensors/imu.h"
#include "sensors/lidar.h"
#include "sensors/sensorRegistry.h"
#include "state/stateManager.h"
#include "logging/logger.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>


int main()
{
    SensorRegistry registry;
    StateManager& sm = StateManager::getInstance();
    sm.registerCallback([](robotState ns){
                                Logger::getInstance().log(logLevel::INFO, 
                                        "Observer notified - new state: " + StateManager::getInstance().getStateStr(ns) );
                                        });

    
    registry.addSensor(std::make_unique<Imu>("base_imu"));
    registry.addSensor(std::make_unique<Lidar>("lidar3D", 10));


    sm.setState(robotState::RUNNING);
    registry.startAll();

    for(size_t i = 0 ; i < 5; ++i)
    {
        registry.displayAll();
       
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    registry.stopAll();
    sm.setState(robotState::STOPPED);

    std::cin.get();
    return 0;
}