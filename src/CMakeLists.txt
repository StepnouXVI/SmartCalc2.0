cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_TOOLCHAIN_FILE /home/stm/tools/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
project(SmartCalc VERSION 2.0)



add_subdirectory(CalculationRpn)
add_subdirectory(OperationsForCalculation)
add_subdirectory(Libs)
add_subdirectory(Ui)
add_subdirectory(Controllers)
add_subdirectory(SmartCalc)

