set(namespace "SmartCalc")
project(
  "TestsForOperations"
  VERSION 0.1.1
  DESCRIPTION "Tests for lib - CalculationOperations")

set(TEST_SOURCE src/main.cpp)

# find_package(GTest CONFIG REQUIRED)
include_directories(include)

add_executable(${PROJECT_NAME} ${TEST_SOURCE})
target_link_libraries(
  ${PROJECT_NAME}
  CalculationOperations
  Calculation
  GTest::gtest
  GTest::gtest_main
  GTest::gmock
  GTest::gmock_main)

add_test(NAME tests_for_operations COMMAND ${PROJECT_NAME})
