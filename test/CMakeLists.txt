enable_testing()

add_executable(
  package_test
  PackageTest.cpp
  ../src/Package.cpp
)

target_include_directories(package_test PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../src/>
)

target_link_libraries(
  package_test 
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(package_test)
