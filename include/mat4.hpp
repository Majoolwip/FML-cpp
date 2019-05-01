#ifndef FML_MAT4_HEADER
#define FML_MAT4_HEADER

#include<array>

namespace fml {
  template<typename T>
  struct Mat4 {
    std::array<T,16> m;

    static constexpr Mat4<T> init_identity_mat4() noexcept {
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

    static constexpr Mat4<T> init_translation_mat4(
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

    static constexpr Mat4<T> init_scale_mat4(
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
  };

}

#endif
