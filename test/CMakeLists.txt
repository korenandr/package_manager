enable_testing()

add_executable(
  package_test
  PackageTest.cpp
  ../src/Package.cpp
  cmd/CreateTest.cpp
  cmd/AddTest.cpp
  cmd/RemoveTest.cpp
  cmd/PrintTest.cpp
  cmd/HelpTest.cpp
  cmd/ExitTest.cpp
  ../src/utils/InputCommandValidator.cpp
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
