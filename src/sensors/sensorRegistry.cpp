#include "sensors/sensorRegistry.h"
#include <chrono>

SensorRegistry::SensorRegistry() 
{
    sensorThreads.reserve(10);
}

void SensorRegistry::addSensor(std::unique_ptr<Sensor> sensor)
{
    auto st = std::make_unique<SensorThread>();
    st->sensor = std::move(sensor);
    sensorThreads.emplace_back(std::move(st));
}

void SensorRegistry::startAll()
{
    for(auto& itemPtr: sensorThreads)
    {
        Logger::getInstance().log(logLevel::INFO, "Starting sensor: " + itemPtr->sensor->getName());
        itemPtr->running = true;
        auto *ptr = itemPtr.get();
        itemPtr->thread = std::thread([ptr](){
            while (ptr->running)
            {
                {
                    std::lock_guard<std::mutex> lock(ptr->mtx);
                    ptr->sensor->update();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        });
    }
}
void SensorRegistry::stopAll()
{
    for(auto& itemPtr: sensorThreads)
    {
        Logger::getInstance().log(logLevel::INFO, "Stopping sensor: " + itemPtr->sensor->getName());
        itemPtr->running = false;
        if(itemPtr->thread.joinable()) itemPtr->thread.join();
    }
}

void SensorRegistry::displayAll() const
{
    for(const auto& itemPtr: sensorThreads)
    {
        std::lock_guard<std::mutex> lock(itemPtr->mtx);
        itemPtr->sensor->display();
    }
}

