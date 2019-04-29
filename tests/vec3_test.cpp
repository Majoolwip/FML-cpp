#define BOOST_TEST_MODULE Vec3
#include "../include/vec3.hpp"
#include <boost/test/included/unit_test.hpp>
#include <cmath>

#define EPSILON 0.00001

BOOST_AUTO_TEST_CASE(length_test)
{
  fml::Vec3<double> a {1.0, 2.0, 3.0};
  auto len = a.length();
  BOOST_TEST(len == std::sqrt(1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0));
}

BOOST_AUTO_TEST_CASE(normalized_test)
{
  fml::Vec3<double> a {1.0, 2.0, 3.0};
  auto len = a.normalized().length();
  BOOST_TEST(std::abs(len - 1.0) <= EPSILON);
}

BOOST_AUTO_TEST_CASE(cross_test)
{
  fml::Vec3<double> x {1.0, 0.0, 0.0};
  fml::Vec3<double> y {0.0, 1.0, 0.0};
  fml::Vec3<double> z {0.0, 0.0, 1.0};
  BOOST_TEST(z.partial_eq(x.cross(y), EPSILON));
  BOOST_TEST(y.partial_eq(z.cross(x), EPSILON));
  BOOST_TEST(x.partial_eq(y.cross(z), EPSILON));
}

BOOST_AUTO_TEST_CASE(dot_test)
{
  fml::Vec3<double> x {1.0, 0.0, 0.0};
  fml::Vec3<double> y {0.0, 1.0, 0.0};
  fml::Vec3<double> z {0.0, 0.0, 1.0};
  BOOST_TEST(std::abs(x.dot(y)) < EPSILON);
  BOOST_TEST(std::abs(y.dot(z)) < EPSILON);
  BOOST_TEST(std::abs(x.dot(z)) < EPSILON);
  BOOST_TEST(std::abs(x.dot(x) - 1.0) < EPSILON);
  BOOST_TEST(std::abs(y.dot(y) - 1.0) < EPSILON);
  BOOST_TEST(std::abs(z.dot(z) - 1.0) < EPSILON);
}


BOOST_AUTO_TEST_CASE(abs_test)
{
  fml::Vec3<double> a {-1.0, -2.0, -3.0};
  fml::Vec3<double> expected {1.0, 2.0, 3.0};
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
