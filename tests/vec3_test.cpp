#define BOOST_TEST_MODULE Vec3
#include "../include/vec3.hpp"
#include <boost/test/included/unit_test.hpp>
#include <cmath>

#define EPSILON 0.00001

BOOST_AUTO_TEST_CASE(length_test)
{
  constexpr fml::Vec3<double> a {1.0, 2.0, 3.0};
  const auto len = a.length();
  BOOST_TEST(len == std::sqrt(1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0));
}

BOOST_AUTO_TEST_CASE(normalized_test)
{
  constexpr fml::Vec3<double> a {1.0, 2.0, 3.0};
  const auto len = a.normalized().length();
  BOOST_TEST(std::abs(len - 1.0) <= EPSILON);
}

BOOST_AUTO_TEST_CASE(cross_test)
{
  const fml::Vec3<double> x {1.0, 0.0, 0.0};
  const fml::Vec3<double> y {0.0, 1.0, 0.0};
  const fml::Vec3<double> z {0.0, 0.0, 1.0};
  BOOST_TEST(z.partial_eq(x.cross(y), EPSILON));
  BOOST_TEST(y.partial_eq(z.cross(x), EPSILON));
  BOOST_TEST(x.partial_eq(y.cross(z), EPSILON));
}

BOOST_AUTO_TEST_CASE(dot_test)
{
  const fml::Vec3<double> x {1.0, 0.0, 0.0};
  const fml::Vec3<double> y {0.0, 1.0, 0.0};
  const fml::Vec3<double> z {0.0, 0.0, 1.0};
  BOOST_TEST(std::abs(x.dot(y)) < EPSILON);
  BOOST_TEST(std::abs(y.dot(z)) < EPSILON);
  BOOST_TEST(std::abs(x.dot(z)) < EPSILON);
  BOOST_TEST(std::abs(x.dot(x) - 1.0) < EPSILON);
  BOOST_TEST(std::abs(y.dot(y) - 1.0) < EPSILON);
  BOOST_TEST(std::abs(z.dot(z) - 1.0) < EPSILON);
}


BOOST_AUTO_TEST_CASE(abs_test)
{
  const fml::Vec3<double> a {-1.0, -2.0, -3.0};
  const fml::Vec3<double> expected {1.0, 2.0, 3.0};
  BOOST_TEST(a.abs().partial_eq(expected, EPSILON));
}

BOOST_AUTO_TEST_CASE(clamp_test)
{
  fml::Vec3<double> a {0.0, 0.0, 0.0};
  fml::Vec3<double> expected {0.0, 0.0, 0.0};
  BOOST_TEST(a.clamp(-1.0, 1.0).partial_eq(expected, EPSILON));
  a = {-2.0, -2.0, -2.0};
  expected = {-1.0, -1.0, -1.0};
  BOOST_TEST(a.clamp(-1.0, 1.0).partial_eq(expected, EPSILON));
  a = {2.0, 2.0, 2.0};
  expected = {1.0, 1.0, 1.0};
  BOOST_TEST(a.clamp(-1.0, 1.0).partial_eq(expected, EPSILON));

}

BOOST_AUTO_TEST_CASE(vec_add)
{
  constexpr fml::Vec3<double> a {1.0, 2.0, 3.0};
  constexpr fml::Vec3<double> b = a + a;
  constexpr fml::Vec3<double> c = a + b;
  BOOST_TEST(b.partial_eq({2.0, 4.0, 6.0}, EPSILON));
  BOOST_TEST(c.partial_eq({3.0, 6.0, 9.0}, EPSILON));
}

BOOST_AUTO_TEST_CASE(vec_sub)
{
  constexpr fml::Vec3<double> a {1.0, 2.0, 3.0};
  constexpr fml::Vec3<double> b = a - a;
  constexpr fml::Vec3<double> c = a - fml::Vec3<double>{0.5, 0.8, 1.0};
  BOOST_TEST(b.partial_eq({0.0, 0.0, 0.0}, EPSILON));
  BOOST_TEST(c.partial_eq({0.5, 1.2, 2.0}, EPSILON));
}

BOOST_AUTO_TEST_CASE(vec_mul)
{
  constexpr fml::Vec3<double> a {1.0, 2.0, 3.0};
  constexpr fml::Vec3<double> b = a * a;
  constexpr fml::Vec3<double> c = a * 5.0;
  constexpr fml::Vec3<double> d = 5.0 * a;
  BOOST_TEST(b.partial_eq({1.0, 4.0, 9.0}, EPSILON));
  BOOST_TEST(c.partial_eq({5.0, 10.0, 15.0}, EPSILON));
  BOOST_TEST(d.partial_eq({5.0, 10.0, 15.0}, EPSILON));
}

BOOST_AUTO_TEST_CASE(vec_div)
{
  constexpr fml::Vec3<double> a {1.0, 2.0, 3.0};
  constexpr fml::Vec3<double> b = a / a;
  constexpr fml::Vec3<double> c = a / 5.0;
  BOOST_TEST(b.partial_eq({1.0, 1.0, 1.0}, EPSILON));
  BOOST_TEST(c.partial_eq({1.0 / 5.0, 2.0 / 5.0, 3.0 / 5.0}, EPSILON));
}
