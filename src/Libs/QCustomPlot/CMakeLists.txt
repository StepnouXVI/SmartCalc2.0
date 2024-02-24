cmake_minimum_required(VERSION 3.12)

set(namespace "SmartCalc")
project(
  "QCustomPlot"
  VERSION 0.1.1
  DESCRIPTION "This lib contains ui elements for charts")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_library(${PROJECT_NAME} STATIC)

file(GLOB_RECURSE LIB_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE LIB_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "include/*.h")


target_sources(${PROJECT_NAME}
    PRIVATE
        ${LIB_SOURCES}
        ${LIB_HEADERS}
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE # Список директорий, в который библиотека будет искать свои внутренние
          # заголовки
          ${CMAKE_CURRENT_SOURCE_DIR}/include
  PUBLIC # где другие проекты будут видеть библиотеки
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         # где внешние проекты будут искать публичные заголовки библиотеки
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)


find_package(
  QT NAMES Qt6 Qt5
  COMPONENTS Core
  REQUIRED)

find_package(Qt${QT_VERSION_MAJOR}PrintSupport REQUIRED)

find_package(
  Qt${QT_VERSION_MAJOR}
  COMPONENTS Gui
  REQUIRED)

target_link_libraries(
  ${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Gui
                         Qt${QT_VERSION_MAJOR}::PrintSupport)


                         cmake_minimum_required(VERSION 3.15)


# not for MSVC
if(CMAKE_COMPILER_IS_GNUCXX)
    # compile options for this target only
    # treat warnings as errors
    target_compile_options(${PROJECT_NAME} PRIVATE -Werror)
endif()

