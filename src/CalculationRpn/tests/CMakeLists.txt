project(tests)

set(TEST_SOURCE src/main.cpp)

find_package(GTest CONFIG REQUIRED)
include_directories(include ../include/private ../include/public)


add_executable(simple_test ${TEST_SOURCE})
target_link_libraries(simple_test CalculationRpn GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME SimpleTest COMMAND simple_test)
