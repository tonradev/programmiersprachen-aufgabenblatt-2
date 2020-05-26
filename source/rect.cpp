#include "rect.hpp"

Rect::Rect(Vec2 const& min, Vec2 const& max, Color const& color):
    min_{min},
    max_{max},
    color_{color}
    {}

float Rect::circumference() const{
    if ((max_.x-min_.x) < 0 || (max_.y-min_.y) < 0) {
        return 0;
    }
    else {
        return (max_.x-min_.x)*2+(max_.y-min_.y)*2;
    }
}


void Rect::draw(Window const& target, float thickness = 1.0f) {
    thickness_ = thickness;
    target.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness_);
    target.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness_);
    target.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness_);
    target.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness_);
}

bool Rect::is_inside(Vec2 const& point) const{
    if (point.x >= min_.x && point.x <= max_.x && point.y >= min_.y && point.y <= max_.y) {
        return true;
    }
    else {
        return false;
    }
}