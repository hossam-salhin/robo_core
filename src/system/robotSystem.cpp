#include "system/robotSystem.h"
#include "sensors/imu.h"
#include "sensors/lidar.h"
#include <thread>
#include <chrono>

RobotSystem::RobotSystem(const std::string& path)
{
    config_path = path;
}

bool RobotSystem::initialize()
{
    auto& logger = Logger::getInstance();

    if(!config.load(config_path))
    {
        StateManager::getInstance().setState(robotState::ERROR);
        return false;
    };
    std::string imuName = config.getString("imu_name", "imu");
    std::string lidarName = config.getString("lidar_name", "lidar");
    int beams = config.getInt("lidar_beams", 10);
    logger.log(logLevel::INFO,"Config file loaded.");

    auto& sm = StateManager::getInstance();
    sm.registerCallback([](robotState ns){
            Logger::getInstance().log(logLevel::INFO, 
            "Observer notified - new state: " + StateManager::getInstance().getStateStr(ns));
            });

    logger.log(logLevel::INFO, "State manager created");

    registry.addSensor(std::make_unique<Imu>(imuName));
    registry.addSensor(std::make_unique<Lidar>(lidarName,beams));
    logger.log(logLevel::INFO, "Sensors created and set into the register");

    sm.setState(robotState::RUNNING);
    registry.startAll();

    return true;
}

void RobotSystem::spin(int cycle)
{
    for(size_t i = 0 ; i < cycle; ++i)
    {
        registry.displayAll();
       
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void RobotSystem::shutdown()
{
    registry.stopAll();
    StateManager::getInstance().setState(robotState::STOPPED);
}
