cmake_minimum_required(VERSION 3.10)


project(robo_core)

set(CMAKE_CXX_STANDARD 17)


include_directories(include)

add_executable(robo_core
    src/sensors/imu.cpp
    src/sensors/lidar.cpp
    src/sensors/sensorRegistry.cpp
    src/logging/logger.cpp
    src/state/stateManager.cpp
    src/config/configLoader.cpp
    src/app.cpp

)

target_link_libraries(robo_core stdc++fs)

