#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

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
