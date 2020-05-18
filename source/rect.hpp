#ifndef RECT_HPP
#define RECT_HPP
#include "vec2.hpp"

class Rect {
    public:
        Rect() = default;
        Rect(Vec2 const& min, Vec2 const& max);
    private:
        Vec2 min_{0,0};
        Vec2 max_{1,1};
};

#endif