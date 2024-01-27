set(namespace "SmartCalc")
project("TestsForDeposit"
    VERSION 0.1.1
    DESCRIPTION "Tests for lib - Deposit"
)

set(TEST_SOURCE src/main.cpp)

include_directories(include)


add_executable(${PROJECT_NAME} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME} Deposit GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME tests_for_deposit COMMAND ${PROJECT_NAME})
