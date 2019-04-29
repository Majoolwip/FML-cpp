#ifndef VEC3_HEADER
#define VEC3_HEADER
#include <assert.h>
#include <type_traits>
#include <cmath>
#include <algorithm>

namespace fml {

  template<typename T>
  struct Vec3 {
    T x;
    T y;
    T z;

    constexpr T length() const noexcept {
      return std::sqrt(x * x + y * y + z * z);
    }

    constexpr Vec3<T> normalized() const noexcept {
      const T length = this->length();
      if constexpr (std::is_same<T,int>::value) {
        if (length == 0) {
          return Vec3 {0, 0, 0};
        } else {
          return Vec3 {x / length, y / length, z / length};
        }
      } else {
        assert(length != 0.0);
        return Vec3 {x / length, y / length, z / length};
      }
    }

    constexpr T distance(const Vec3<T>& other) const noexcept {
      return (other - *this).length();
    }

    constexpr Vec3<T> add_scaled_vec(const Vec3<T>& direction, const T scale) {
      return Vec3 {std::fma(direction.x, scale, x),
                   std::fma(direction.y, scale, y),
                   std::fma(direction.z, scale, z)};
    }

    constexpr T dot(const Vec3<T>& other) const noexcept {
      return x * other.x + y * other.y + z * other.z;
    }

    constexpr Vec3<T> cross(const Vec3<T>& other) const noexcept {
      return Vec3<T> {y * other.z - z * other.y,
                      z * other.x - x * other.z,
                      x * other.y - y * other.x};
    }

    constexpr Vec3<T> clamp(const T min, const T max) const noexcept {
      T nx = std::min(std::max(x, min), max);
      T ny = std::min(std::max(y, min), max);
      T nz = std::min(std::max(z, min), max);
      return Vec3<T> {nx, ny, nz};
    }

    constexpr Vec3<T> abs() const noexcept {
      return Vec3<T> {std::abs(x), std::abs(y), std::abs(z)};
    }

    constexpr bool partial_eq(const Vec3<T>& other, const T epsilon) {
      return std::abs(x - other.x) < epsilon &&
             std::abs(y - other.y) < epsilon &&
             std::abs(z - other.z) < epsilon;
    }

    constexpr Vec3<T> operator+ (const Vec3<T>& right) const noexcept {
      return Vec3<T> {this->x + right.x, this->y + right.y, this->z + right.z};
    }

    constexpr Vec3<T> operator+= (const Vec3<T>& right) noexcept {
      x += right.x;
      y += right.y;
      z += right.z;
    }

    constexpr Vec3<T> operator- (const Vec3<T>& right) const noexcept {
      return Vec3<T> {this->x - right.x, this->y - right.y, this->z - right.z};
    }

    constexpr Vec3<T> operator-= (const Vec3<T>& right) noexcept {
      x -= right.x;
      y -= right.y;
      z -= right.z;
    }

    constexpr Vec3<T> operator* (const T right) const noexcept {
      return Vec3<T> {this->x * right, this->y * right, this->z * right};
    }

    constexpr Vec3<T> operator* (const Vec3<T>& right) const noexcept {
      return Vec3<T> {this->x * right.x, this->y * right.y, this->z * right.z};
    }

    constexpr Vec3<T> operator*= (const Vec3<T>& right) noexcept {
      x *= right.x;
      y *= right.y;
      z *= right.z;
    }

    constexpr Vec3<T> operator/ (const Vec3<T>& right) const noexcept {
      return Vec3<T> {this->x / right.x, this->y / right.y, this->z / right.z};
    }

    constexpr Vec3<T> operator/= (const Vec3<T>& right) noexcept {
      x /= right.x;
      y /= right.y;
      z /= right.z;
    }
  };

  template<typename T>
  constexpr Vec3<T> operator* (const T left, const Vec3<T>& right) {
      return Vec3<T> {left * right.x, left * right.y, left * right.z};
  }
}

#endif
