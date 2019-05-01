#define BOOST_TEST_MODULE Mat4
#include "../include/mat4.hpp"
#include <boost/test/included/unit_test.hpp>
#include <cmath>

#define EPSILON 0.00001

BOOST_AUTO_TEST_CASE(identity_test)
{
  fml::Mat4<float> m = fml::Mat4<float>::init_identity();
  BOOST_TEST(m.m[ 0] == 1.0f);
  BOOST_TEST(m.m[ 1] == 0.0f);
  BOOST_TEST(m.m[ 2] == 0.0f);
  BOOST_TEST(m.m[ 3] == 0.0f);

  BOOST_TEST(m.m[ 4] == 0.0f);
  BOOST_TEST(m.m[ 5] == 1.0f);
  BOOST_TEST(m.m[ 6] == 0.0f);
  BOOST_TEST(m.m[ 7] == 0.0f);

  BOOST_TEST(m.m[ 8] == 0.0f);
  BOOST_TEST(m.m[ 9] == 0.0f);
  BOOST_TEST(m.m[10] == 1.0f);
  BOOST_TEST(m.m[11] == 0.0f);

  BOOST_TEST(m.m[12] == 0.0f);
  BOOST_TEST(m.m[13] == 0.0f);
  BOOST_TEST(m.m[14] == 0.0f);
  BOOST_TEST(m.m[15] == 1.0f);
}

BOOST_AUTO_TEST_CASE(translation_test)
{
  fml::Mat4<float> m = fml::Mat4<float>::init_translation(2.0, 3.0, 4.0);
  BOOST_TEST(m.m[ 0] == 1.0f);
  BOOST_TEST(m.m[ 1] == 0.0f);
  BOOST_TEST(m.m[ 2] == 0.0f);
  BOOST_TEST(m.m[ 3] == 0.0f);

  BOOST_TEST(m.m[ 4] == 0.0f);
  BOOST_TEST(m.m[ 5] == 1.0f);
  BOOST_TEST(m.m[ 6] == 0.0f);
  BOOST_TEST(m.m[ 7] == 0.0f);

  BOOST_TEST(m.m[ 8] == 0.0f);
  BOOST_TEST(m.m[ 9] == 0.0f);
  BOOST_TEST(m.m[10] == 1.0f);
  BOOST_TEST(m.m[11] == 0.0f);

  BOOST_TEST(m.m[12] == 2.0f);
  BOOST_TEST(m.m[13] == 3.0f);
  BOOST_TEST(m.m[14] == 4.0f);
  BOOST_TEST(m.m[15] == 1.0f);
}

BOOST_AUTO_TEST_CASE(scale_test)
{
  fml::Mat4<float> m = fml::Mat4<float>::init_scale(2.0, 3.0, 4.0);
  BOOST_TEST(m.m[ 0] == 2.0f);
  BOOST_TEST(m.m[ 1] == 0.0f);
  BOOST_TEST(m.m[ 2] == 0.0f);
  BOOST_TEST(m.m[ 3] == 0.0f);

  BOOST_TEST(m.m[ 4] == 0.0f);
  BOOST_TEST(m.m[ 5] == 3.0f);
  BOOST_TEST(m.m[ 6] == 0.0f);
  BOOST_TEST(m.m[ 7] == 0.0f);

  BOOST_TEST(m.m[ 8] == 0.0f);
  BOOST_TEST(m.m[ 9] == 0.0f);
  BOOST_TEST(m.m[10] == 4.0f);
  BOOST_TEST(m.m[11] == 0.0f);

  BOOST_TEST(m.m[12] == 0.0f);
  BOOST_TEST(m.m[13] == 0.0f);
  BOOST_TEST(m.m[14] == 0.0f);
  BOOST_TEST(m.m[15] == 1.0f);
}
