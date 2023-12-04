cmake_minimum_required(VERSION 3.12)

set(CMAKE_TOOLCHAIN_FILE /home/stm/tools/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
project(SmartCalc)

add_subdirectory(CalculationRpn)
add_subdirectory(OperationsForCalculation)
add_subdirectory(Libs)
add_subdirectory(Ui)
add_subdirectory(CompositionRoot)
