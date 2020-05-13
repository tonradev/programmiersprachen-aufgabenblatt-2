#include "vec2.hpp"

// Vec2: Definition of methods

Vec2& Vec2::operator+=(Vec2 const& v)
{
    x += v.x;
    y += v.y;
    return *this;
}
Vec2& Vec2::operator-=(Vec2 const& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}
Vec2& Vec2::operator*=(float s)
{
    x *= s;
    y *= s;
    return *this;
}
Vec2& Vec2::operator/=(float s)
{
    x /= s;
    y /= s;
    return *this;
}