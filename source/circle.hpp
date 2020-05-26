#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
    public:
        Circle() = default;
        Circle(Vec2 const& center, float radius, Color const& color);
        float circumference() const;
        void draw(Window const& target, float thickness);
        bool is_inside(Vec2 const& point) const;
        float thickness_{1.0f};
    private:
        Vec2 center_{0,0};
        float radius_{1.0f};
        Color color_{0.5,0.5,0.5};
};

#endif // CIRCLE_HPP