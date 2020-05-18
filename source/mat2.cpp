#include "mat2.hpp"
#include <iostream>

// Define member function
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

// Define free function
Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
    return Mat2{(m1.e_00*m2.e_00 + m1.e_10*m2.e_01), (m1.e_00*m2.e_10 + m1.e_10*m2.e_11), (m1.e_01*m2.e_00 + m1.e_11*m2.e_01), (m1.e_01*m2.e_10 + m1.e_11*m2.e_11)};
}