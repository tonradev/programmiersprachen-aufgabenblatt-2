#include "rect.hpp"

Rect::Rect(Vec2 const& min, Vec2 const& max):
    min_{min},
    max_{max}
    {}

float Rect::circumference() const{
    if ((max_.x-min_.x) < 0 || (max_.y-min_.y) < 0) {
        return 0;
    }
    else {
        return (max_.x-min_.x)*2+(max_.y-min_.y)*2;
    }
}