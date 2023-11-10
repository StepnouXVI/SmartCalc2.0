project(tests)

set(TEST_SOURCE src/main.cpp)

find_package(GTest CONFIG REQUIRED)
include_directories(include ../include/public)


add_executable(OperationTests ${TEST_SOURCE})
target_link_libraries(OperationTests  OperationForCalculation CalculationRpn GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME SimpleTest COMMAND OperationTests)
