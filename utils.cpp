#include "utils.h"

#include <cmath>


constexpr float radians(float degrees)
{
    return degrees * (PI<float> / 180);
}


constexpr float degrees(float radians)
{
    return radians * (180 / PI<float>);
}


float move_x(float degrees)
{
    return cosf(radians(degrees));
}


float move_y(float degrees)
{
    return sinf(radians(degrees));
}


float look_at_direction(float x_offset, float y_offset)
{
    return degrees(atan2f(y_offset, x_offset));
}