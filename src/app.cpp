#include "system/robotSystem.h"
#include <iostream>
#include <chrono>
#include <vector>


int main()
{
    std::string config_path = "../config/robot_config.cfg"; 
    RobotSystem system(config_path);

    if(!system.initialize())
    {
        return 1;
    }

    system.spin(10);
    system.shutdown();
    std::cin.get();
    
    return 0;
}