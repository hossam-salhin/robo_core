#pragma once 
#include "sensor.h"
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>


struct SensorThread
{
    std::unique_ptr<Sensor> sensor;
    std::thread thread;
    mutable std::mutex mtx;
    std::atomic<bool> running{false};
};



class SensorRegistry 
{
    public:
    SensorRegistry();
    void addSensor(std::unique_ptr<Sensor> sensor);
    void displayAll() const;
    void startAll();
    void stopAll();

    private:
    std::vector<std::unique_ptr<SensorThread>> sensorThreads; 
};

