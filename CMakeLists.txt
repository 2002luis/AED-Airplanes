cmake_minimum_required(VERSION 3.23)
project(AED_Airplane)

set(CMAKE_CXX_STANDARD 14)

add_executable(AED_Airplane src/main.cpp src/Airport.h src/Airport.cpp)
