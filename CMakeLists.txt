cmake_minimum_required(VERSION 3.2)

if (MSVC)
  add_compile_options(/W4)
else ()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
  execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json
  )
endif()

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

set(needed_features cxx_constexpr cxx_relaxed_constexpr)
set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_executable(vec3_test ./tests/vec3_test.cpp)
add_test(Vec3_test vec3_test)
target_link_libraries(vec3_test ${Boost_FILESYSTEM_LIBRARY}
                                  ${Boost_SYSTEM_LIBRARY}
                                  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_compile_features(vec3_test PRIVATE ${needed_features})
