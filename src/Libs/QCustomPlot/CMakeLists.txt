cmake_minimum_required(VERSION 3.12)
project(SmartCalc)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(QCustomPlot STATIC ${SOURCES})

target_include_directories(QCustomPlot
    PRIVATE
         # Список директорий, в который библиотека будет искать свои внутренние заголовки
        ${CMAKE_CURRENT_SOURCE_DIR}/include

    PUBLIC
        # где другие проекты будут видеть библиотеки
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # где внешние проекты будут искать публичные заголовки библиотеки
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

find_package(Qt6 COMPONENTS Core REQUIRED)
target_link_libraries(QCustomPlot
    PUBLIC
    Qt6::Core)

# enable_testing()

# add_subdirectory(tests)
