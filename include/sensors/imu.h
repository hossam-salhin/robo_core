#pragma once
#include "vec3.h"
#include "sensor.h"
#include <random>


class Imu : public Sensor
{
    private:
        Vec3 accel{0 ,0 ,0};
        Vec3 gyro{0 ,0 ,0};
        std::random_device rd;
        std::mt19937 gen{rd()};
        std::uniform_real_distribution<float> dist{-2.0f, 2.0f};
        std::uniform_real_distribution<float> gyr{-0.1f, 0.1f};
    public:
        Imu(const std::string& name);
        void update() override;
        void display() const override;
};



