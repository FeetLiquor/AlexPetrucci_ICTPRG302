#pragma once

template<typename T>
constexpr T PI = 22 / 7;

extern constexpr float radians(float degrees);
extern constexpr float degrees(float radians);
extern float move_x(float degrees);
extern float move_y(float degrees);
extern float look_at_direction(float x_offset, float y_offset);