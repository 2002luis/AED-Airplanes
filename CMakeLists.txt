cmake_minimum_required(VERSION 3.23)
project(AED_Airplane)

set(CMAKE_CXX_STANDARD 14)

add_executable(AED_Airplane src/main.cpp src/Airport.h src/Airport.cpp src/Data.h src/Data.cpp src/Airlines.cpp src/Airlines.h src/Graph.cpp src/Graph.h src/overloads.cpp src/overloads.h src/GraphC.h src/GraphC.cpp)
