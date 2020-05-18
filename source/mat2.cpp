#include "mat2.hpp"
#include <cmath>

// Define member functions
Mat2& Mat2::operator*=(Mat2 const& m)
{
    float e_00_new = e_00*m.e_00 + e_10*m.e_01;
    float e_10_new = e_00*m.e_10 + e_10*m.e_11;
    float e_01_new = e_01*m.e_00 + e_11*m.e_01;
    float e_11_new = e_01*m.e_10 + e_11*m.e_11;
    e_00 = e_00_new;
    e_10 = e_10_new;
    e_01 = e_01_new;
    e_11 = e_11_new;
    return *this;
}

float Mat2::det() const{
    return (e_00*e_11-e_10*e_01);
}

// Define free functions
Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
    Mat2 res = {m1};
    return res*=m2;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v)
{
    return Vec2{((m.e_00*v.x)+(m.e_10*v.y)), ((m.e_01*v.x)+(m.e_11*v.y))};
}

Mat2 inverse(Mat2 const& m)
{
    if (m.det() != 0) {
        float e_00 = (1/m.det())*m.e_11;
        float e_10 = (1/m.det())*(-m.e_10);
        float e_01 = (1/m.det())*(-m.e_01);
        float e_11 = (1/m.det())*m.e_00;
        return Mat2{e_00, e_10, e_01, e_11};
    }
    else
    {
        return Mat2{0, 0, 0, 0};
    }
    
}

Mat2 transpose(Mat2 const& m)
{
    return Mat2{m.e_00, m.e_01, m.e_10, m.e_11};
}

Mat2 make_rotation_mat2(float phi)
{
    return Mat2{std::cos(phi), -(std::sin(phi)), std::sin(phi), std::cos(phi)};
}