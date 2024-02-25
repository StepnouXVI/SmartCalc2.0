cmake_minimum_required(VERSION 3.12)

project(
  "SmartCalc"
  VERSION 2.0
  DESCRIPTION "Smart Calculator application")

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(third_party)
add_subdirectory(Calculation)
add_subdirectory(CalculationOperations)
add_subdirectory(Credit)
add_subdirectory(Deposit)
add_subdirectory(Libs)
add_subdirectory(Ui)
add_subdirectory(Controllers)

add_subdirectory(SmartCalc)
