cmake_minimum_required(VERSION 3.12)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB_RECURSE LIB_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(UI STATIC ${LIB_SOURCES})

target_include_directories(UI
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

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}PrintSupport REQUIRED)

target_link_libraries(UI
    PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
    QCustomPlot
)