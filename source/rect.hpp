#ifndef RECT_HPP
#define RECT_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rect {
    public:
        Rect() = default;
        Rect(Vec2 const& min, Vec2 const& max, Color const& color);
        float circumference() const;
        void draw(Window const& target, float thickness);
        bool is_inside(Vec2 const& point) const;
        float thickness_{1.0f};
    private:
        Vec2 min_{0,0};
        Vec2 max_{1,1};
        Color color_{0.3,0.3,0.3};
};

#endif