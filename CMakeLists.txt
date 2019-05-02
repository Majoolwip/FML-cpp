cmake_minimum_required(VERSION 3.2)

if (MSVC)
  add_compile_options(/W4 /permissive)
else ()
  add_compile_options(-Wall
                      -Wextra
                      -Wpedantic
                      -Wshadow
                      -Wconversion
                      -Wsign-conversion
                      -Wuseless-cast
                      -Wdouble-promotion
                      -Wunused
                      -Winvalid-constexpr)
endif ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
  execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json
  )
endif()

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_executable(vec3_test ./tests/vec3_test.cpp)
add_test(Vec3_test vec3_test)
target_include_directories(vec3_test PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(vec3_test ${Boost_FILESYSTEM_LIBRARY}
                                  ${Boost_SYSTEM_LIBRARY}
                                  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_executable(mat4_test ./tests/mat4_test.cpp)
add_test(Mat4_test mat4_test)
target_include_directories(mat4_test PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(mat4_test ${Boost_FILESYSTEM_LIBRARY}
                                  ${Boost_SYSTEM_LIBRARY}
                                  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
