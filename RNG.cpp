#include "RNG.h"

#include <chrono>


RNG RNG::_instance;


RNG::RNG()
    : _generator(std::chrono::steady_clock::now().time_since_epoch().count())
{
}


int RNG::get_int(int min, int max)
{
    std::uniform_int_distribution dist(min, max);
    return dist(_instance._generator);
}


float RNG::get_float(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(_instance._generator);
}