#include "circle.hpp"
#include <cmath>
#include "mat2.hpp"
#include <iostream>

Circle::Circle(Vec2 const& center, float radius, Color const& color):
    center_{center}, 
    radius_{radius},
    color_{color}
    {}

float Circle::circumference() const{
    if (radius_ < 0) {
        return 0;
    }
    else {
        return M_PI*2*radius_;
    }
}


void Circle::draw(Window const& target, float thickness = 1.0f) {
    thickness_ = thickness;
    Vec2 start_point{(center_.x+radius_), center_.y};
    // target.draw_point((center_.x+radius_),center_.y, color_.r, color_.g, color_.b);
    // target.draw_point(center_.x,center_.y, 0.0f, 0.0f, 0.0f);
    int segments = 30;
    for (int i = 0; i < segments; ++i) {
        Vec2 end_point{start_point};
        end_point-=center_;
        end_point = make_rotation_mat2(((360/segments)*M_PI/180))*end_point;
        end_point+=center_;
        // target.draw_point(end_point.x, end_point.y, color_.r, color_.g, color_.b);
        target.draw_line(start_point.x, start_point.y, end_point.x, end_point.y, color_.r, color_.g, color_.b, thickness_);
        start_point = end_point;
    }
}

bool Circle::is_inside(Vec2 const& point) const{
    if (point.x >= center_.x-radius_ && point.x <= center_.x+radius_ && point.y >= center_.y-radius_ && point.y <= center_.y+radius_) {
        return true;
    }
    else {
        return false;
    }
}