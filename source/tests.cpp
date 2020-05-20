#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rect.hpp"

Vec2 a;
Vec2 b{5.1f, -9.3f};
Vec2 c{2.4f, 5.7f};
Vec2 d{1.1f, 7.3f};
Vec2 e{0.2f, -3.6f};
Vec2 f{-5.3f, 7.9f};
Vec2 g{2.7f, 8.0f};
Vec2 h{4.1f, 19.2f};
Vec2 i{-5.2f, 10.3f};
Vec2 j{23.0f, 16.7f};
Vec2 k{-5.5f, -7.3f};

Vec2 l{3.1f, 2.6f};
Vec2 m{7.4f, 5.0f};
Vec2 n{10.1f, 4.9f};
Vec2 o{0.3f, 1.7f};

Mat2 p{1.0f, 4.0f, 0.0f, -3.0f};
Mat2 q{2.0f, -7.0f, 5.0f, 6.0f};
Mat2 r{1.0f, 2.0f, 3.0f, 4.0f};
Mat2 s{2.0f, 3.0f, 4.0f, 5.0f};

Mat2 t{9.0f, 0.0f, 2.0f, 1.0f};
Mat2 u{2.0f, -3.1f, 2.0f, 1.6f};

Vec2 v{5.0f, 7.0f};
Vec2 w{-0.7f, -4.5f};

TEST_CASE("Struct Vec2 Test", "[Vec2]")
{

  // TESTS FOR EX. 2.3

  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  REQUIRE(b.x == Approx(5.1f));
  REQUIRE(b.y == Approx(-9.3f));
  REQUIRE(c.x == Approx(3.5));
  REQUIRE(c.y == Approx(13.0f));
  REQUIRE(d.x == Approx(1.1f));
  REQUIRE(d.y == Approx(7.3f));
  REQUIRE(e.x == Approx(2.0f));
  REQUIRE(e.y == Approx(-36.0f));
  REQUIRE(f.x == Approx(-6.4f));
  REQUIRE(f.y == Approx(0.6f));
  REQUIRE(g.x == Approx(1.35f));
  REQUIRE(g.y == Approx(4.0f));
  REQUIRE(h.x == Approx(-1.1f));
  REQUIRE(h.y == Approx(29.5f));
  REQUIRE(i.x == Approx(-10.4f));
  REQUIRE(i.y == Approx(20.6f));
  REQUIRE(j.x == Approx(28.5f));
  REQUIRE(j.y == Approx(24.0f));
  REQUIRE(k.x == Approx(-11.0f));
  REQUIRE(k.y == Approx(-14.6f));

  // TESTS FOR EX. 2.4

  REQUIRE((l+m).x == Approx(10.5f));
  REQUIRE((l+m).y == Approx(7.6f));

  REQUIRE((n+o).x == Approx(10.4f));
  REQUIRE((n+o).y == Approx(6.6f));

  REQUIRE((l-m).x == Approx(-4.3f));
  REQUIRE((l-m).y == Approx(-2.4f));

  REQUIRE((n-o).x == Approx(9.8f));
  REQUIRE((n-o).y == Approx(3.2f));

  REQUIRE((3*l).x == Approx(9.3f));
  REQUIRE((3*l).y == Approx(7.8f));

  REQUIRE((5*o).x == Approx(1.5f));
  REQUIRE((5*o).y == Approx(8.5f));

  REQUIRE((l*3).x == Approx(9.3f));
  REQUIRE((l*3).y == Approx(7.8f));

  REQUIRE((n*0.5).x == Approx(5.05f));
  REQUIRE((n*0.5).y == Approx(2.45f));

  REQUIRE((l/2).x == Approx(1.55f));
  REQUIRE((l/2).y == Approx(1.3f));

  REQUIRE((n/1.5).x == Approx(6.733f).epsilon(0.001));
  REQUIRE((n/1.5).y == Approx(3.267f).epsilon(0.001));

}

TEST_CASE("Struct Mat2 Test", "[Mat2]")
{
  // TESTS FOR EX. 2.5

  REQUIRE((p*q).e_00 == 22);
  REQUIRE((p*q).e_10 == 17);
  REQUIRE((p*q).e_01 == -15);
  REQUIRE((p*q).e_11 == -18);

  p*=q;

  REQUIRE(p.e_00 == 22);
  REQUIRE(p.e_10 == 17);
  REQUIRE(p.e_01 == -15);
  REQUIRE(p.e_11 == -18);


  REQUIRE((r*s).e_00 == 10);
  REQUIRE((r*s).e_10 == 13);
  REQUIRE((r*s).e_01 == 22);
  REQUIRE((r*s).e_11 == 29);

  s*=r;

  REQUIRE(s.e_00 == 11);
  REQUIRE(s.e_10 == 16);
  REQUIRE(s.e_01 == 19);
  REQUIRE(s.e_11 == 28);

  Vec2 tv = t*v;

  REQUIRE(tv.x == Approx(45));
  REQUIRE(tv.y == Approx(17));

  Mat2 t_inv = inverse(t);

  REQUIRE(t_inv.e_00 == Approx(0.1111f).epsilon(0.0001));
  REQUIRE(t_inv.e_10 == 0);
  REQUIRE(t_inv.e_01 == Approx(-0.2222f).epsilon(0.0001));
  REQUIRE(t_inv.e_11 == Approx(1.0f));

  Mat2 t_transp = transpose(t);

  REQUIRE(t_transp.e_00 == Approx(9.0f));
  REQUIRE(t_transp.e_10 == Approx(2.0f));
  REQUIRE(t_transp.e_01 == 0);
  REQUIRE(t_transp.e_11 == Approx(1.0f));

  Mat2 t_rot = make_rotation_mat2(1.57);

  REQUIRE(t_rot.e_00 == Approx(0.000796f));
  REQUIRE(t_rot.e_10 == Approx(-0.999f).epsilon(0.1));
  REQUIRE(t_rot.e_01 == Approx(0.999f).epsilon(0.1));
  REQUIRE(t_rot.e_11 == Approx(0.000796f));
}

TEST_CASE("Color struct test", "[Color]")
{
  Color clr_1{};

  REQUIRE(clr_1.r == Approx(0.7f));
  REQUIRE(clr_1.g == Approx(0.7f));
  REQUIRE(clr_1.b == Approx(0.7f));
}

TEST_CASE("Circumference method test", "[circumference]")
{
  Circle c1{{1,1}, 0.5f, {0.4,0.1,0.8}};

  Circle c2{{2,7}, -1.0f, {0.1,0.3,0.8}};

  Rect r1{{0,0},{1,1}, {0.6,0.6,0.6}};

  Rect r2{{3.5f,1.7f}, {4.9f,3.7f}, {0.3,0.1,0.5}};

  REQUIRE(c1.circumference() == Approx(3.14159f));
  REQUIRE(c2.circumference() == 0);
  REQUIRE(r1.circumference() == Approx(4.0f));
  REQUIRE(r2.circumference() == Approx(6.8f));
}

int main(int argc, char *argv[])
{
  // OPERATIONS FOR EX. 2.3

  c += d;
  h += i;

  e *= 10;
  i *= 2;

  f -= d;
  j -= k;

  g /= 2;
  k /= 0.5;

  return Catch::Session().run(argc, argv);
}
