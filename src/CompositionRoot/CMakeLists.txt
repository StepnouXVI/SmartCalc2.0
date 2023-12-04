cmake_minimum_required(VERSION 3.12)

file(GLOB_RECURSE LIB_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_executable(${PROJECT_NAME} ${LIB_SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE PRIVATE 
    CalculationRpn
    OperationForCalculation
    UI
)

# enable_testing()

# add_subdirectory(tests)
