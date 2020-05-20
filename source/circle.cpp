#include "circle.hpp"
#include <cmath>

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