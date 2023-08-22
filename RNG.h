#pragma once

#include <random>


class RNG
{
public:
    RNG(const RNG&) = delete;
    
    static int get_int(int min, int max);
    static float get_float(float min, float max);

private:
    RNG();
    
    static RNG _instance;
    std::mt19937 _generator;
};