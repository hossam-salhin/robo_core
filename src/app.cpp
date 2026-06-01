#include "sensors/imu.h"
#include "sensors/lidar.h"
#include "sensors/sensorRegistry.h"
#include "state/stateManager.h"
#include "logging/logger.h"
#include "config/configLoader.h"
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

    ConfigLoader config;
    config.load("../config/robot_config.cfg");

    std::string imuName = config.getString("imu_name", "imu");
    std::string lidarName = config.getString("lidar_name", "lidar");
    int beams = config.getInt("lidar_beams", 10);

    registry.addSensor(std::make_unique<Imu>(imuName));
    registry.addSensor(std::make_unique<Lidar>(lidarName, beams));


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