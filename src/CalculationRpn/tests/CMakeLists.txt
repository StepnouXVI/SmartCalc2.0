set(namespace "SmartCalc")
project("TestsForCalculationRpn"
    VERSION 0.1.1
    DESCRIPTION "Tests for lib - CalculationRpn"
)

set(TEST_SOURCE src/main.cpp)

# find_package(GTest CONFIG REQUIRED)
include_directories(include ../include/private ../include/public)


add_executable(${PROJECT_NAME} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME} CalculationRpn GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME tests_for_calculation_rpn COMMAND ${PROJECT_NAME})
