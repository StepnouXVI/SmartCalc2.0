cmake_minimum_required(VERSION 3.12)

set(namespace "SmartCalc")
project("CalculationOperations"
    VERSION 0.1.1
    DESCRIPTION "This lib contains Operations data for Calculation"
)

file(GLOB_RECURSE LIB_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
         # Список директорий, в который библиотека будет искать свои внутренние заголовки
        ${CMAKE_CURRENT_SOURCE_DIR}/include/private
        ${CMAKE_CURRENT_SOURCE_DIR}/include/public
    PUBLIC
        # где другие проекты будут видеть библиотеки
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/public>
        # где внешние проекты будут искать публичные заголовки библиотеки
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    Calculation
)

enable_testing()

add_subdirectory(tests)
