#ifndef FML_MAT4_HEADER
#define FML_MAT4_HEADER

#include "vec3.hpp"
#include <array>
#include <cmath>

namespace fml {
  template<typename T>
  struct Mat4 {
    std::array<T,16> m;

    constexpr Vec3<T> transform(const Vec3<T> vec) {
      return Vec3<T> {
        m[0] * vec.x + m[4] * vec.y + m[8] * vec.z + m[12],
        m[1] * vec.x + m[5] * vec.y + m[9] * vec.z + m[13],
        m[2] * vec.x + m[6] * vec.y + m[10] * vec.z + m[14]
      };
    }

    static constexpr Mat4<T> init_identity() noexcept {
      return Mat4<T> {
        {
          1,
          0,
          0,
          0,

          0,
          1,
          0,
          0,

          0,
          0,
          1,
          0,

          0,
          0,
          0,
          1
        }
      };
    }

    static constexpr Mat4<T> init_translation(
      const T x,
      const T y,
      const T z
    ) noexcept {
      return Mat4<T> {
        {
          1,
          0,
          0,
          0,

          0,
          1,
          0,
          0,

          0,
          0,
          1,
          0,

          x,
          y,
          z,
          1
        }
      };
    }

    static constexpr Mat4<T> init_scale(
      const T x,
      const T y,
      const T z
    ) noexcept {
      return Mat4<T> {
        {
          x,
          0,
          0,
          0,

          0,
          y,
          0,
          0,

          0,
          0,
          z,
          0,

          0,
          0,
          0,
          1
        }
      };
    }

    static constexpr Mat4<T> init_rotation(
      const T x,
      const T y,
      const T z
    ) noexcept {
      const T cos_x = std::cos(x);
      const T sin_x = std::sin(x);
      const T cos_y = std::cos(y);
      const T sin_y = std::sin(y);
      const T cos_z = std::cos(z);
      const T sin_z = std::sin(z);
      return Mat4<T> {
        {
          cos_z * cos_y,
          sin_z * cos_y,
          -sin_y,
          0,

          cos_z * sin_y * sin_x + -sin_z * cos_x,
          sin_z * sin_y * sin_x + cos_z * cos_x,
          cos_y * sin_x,
          0,

          cos_z * sin_y * cos_x + -sin_z * -sin_x,
          sin_z * sin_y * cos_x + cos_z * -sin_x,
          cos_y * cos_x,
          0,

          0,
          0,
          0,
          1,
        }
      };
    }

    static constexpr Mat4<T> init_perspective(
      const T fov,
      const T width,
      const T height,
      const T near,
      const T far
    ) noexcept {
      const T half_fov = std::tan(fov / 2.0);
      const T range = near - far;
      const T aspect = width / height;
      return Mat4<T> {
        {
          1.0 / (half_fov * aspect),
          0,
          0,
          0,

          0,
          1.0 / half_fov,
          0,
          0,

          0,
          0,
          (far + near) / range,
          -1,

          0,
          0,
          2.0 * far * near / range,
          0
        }
      };
    }

    static constexpr Mat4<T> init_orthographic(
      const T left,
      const T right,
      const T top,
      const T bottom,
      const T near,
      const T far
    ) noexcept {
      const T width = right - left;
      const T height = top - bottom;
      const T depth = far - near;
      return Mat4<T> {
        {
          2.0 / width,
          0,
          0,
          0,

          0,
          2.0 / height,
          0,
          0,

          0,
          0,
          -2.0 / depth,
          0,

          -(right + left) / width,
          -(top + bottom) / height,
          -(far + near) / depth,
          1
        }
      };
    }
  };

}

#endif
