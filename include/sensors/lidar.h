#pragma once 
#include "sensor.h"
#include <vector>
#include "vec3.h"
#include <random>


class Lidar : public Sensor
{
    public:
    Lidar(const std::string& name, const  uint16_t p_range);
    void update() override;
    void display() const override;

    private:
    const uint16_t range;
    std::vector<Vec3> lidar_readings{{0, 0, 0}};
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_real_distribution<float> point{0.2f, 10.0f};

};

