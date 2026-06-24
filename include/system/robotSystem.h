#pragma once 
#include "sensors/sensorRegistry.h"
#include "logging/logger.h"
#include "state/stateManager.h"
#include "config/configLoader.h"




class RobotSystem
{
    public:
    RobotSystem(const std::string& path);
    bool initialize();
    void spin(int cycle);
    void shutdown();

    private:

    ConfigLoader config;
    SensorRegistry registry;
    std::string config_path;

};