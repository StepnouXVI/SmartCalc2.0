project(ui_tests)

set(TEST_SOURCE src/numpadTests.cpp)

# find_package(GTest CONFIG REQUIRED)
include_directories(include ../include/private ../include/public)


add_executable(numpad ${TEST_SOURCE})
target_link_libraries(numpad  PRIVATE UI Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport )

add_test(NAME SimpleTest COMMAND simple_test)
