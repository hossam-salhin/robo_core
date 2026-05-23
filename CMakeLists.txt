cmake_minimum_required(VERSION 3.10)

project(sensors_simulator)

set(CMAKE_CXX_STANDARD 17)


include_directories(include)

add_executable(sensors_simulator
    src/sensors/imu.cpp
    src/sensors/lidar.cpp
    src/sensors/sensorRegistry.cpp
    src/sensors/app.cpp

)
