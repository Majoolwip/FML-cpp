cmake_minimum_required(VERSION 3.2)

if (MSVC)
  add_compile_options(/W4)
else ()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif ()


enable_testing()
add_executable(tester ./tests/test.cpp)
add_test(MyTest tester)
