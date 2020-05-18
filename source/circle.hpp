#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle {
    public:
        Circle() = default;
        Circle(Vec2 const& center, float radius);
    private:
        Vec2 center_{0,0};
        float radius_{1.0f};
};

#endif // CIRCLE_HPP