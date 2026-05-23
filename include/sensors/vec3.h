#pragma once 
#include <iostream>

struct Vec3
{
    float x{} , y{}, z{};
};

inline std::ostream& operator<< (std::ostream& output, Vec3 const& vec)
{
    output << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return output;
}

