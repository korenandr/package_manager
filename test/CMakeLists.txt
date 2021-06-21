enable_testing()

add_executable(
  package_test
  PackageTest.cpp
  cmd/CreateTest.cpp
  cmd/AddTest.cpp
  cmd/RemoveTest.cpp
  cmd/PrintTest.cpp
  cmd/HelpTest.cpp
  cmd/ExitTest.cpp
  ../src/package/Package.cpp
  ../src/package/PackageController.cpp
  ../src/utils/InputCommandValidator.cpp
)

target_include_directories(package_test PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../src/>
)

target_link_libraries(package_test PRIVATE gtest_main
                                   PRIVATE nlohmann_json)

include(GoogleTest)
gtest_discover_tests(package_test)
