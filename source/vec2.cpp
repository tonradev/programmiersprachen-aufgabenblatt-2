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

// Free functions (ex. 2.4)

Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
    return Vec2 {u.x, u.y}+=v;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v)
{
    return Vec2 {u.x, u.y}-=v;
}

Vec2 operator*(Vec2 const& u, float s)
{
    return Vec2 {u.x, u.y}*=s;
}

Vec2 operator*(float s, Vec2 const& v)
{
    return Vec2 {v.x, v.y}*=s;
}

Vec2 operator/(Vec2 const& u, float s)
{
    return Vec2 {u.x, u.y}/=s;
}