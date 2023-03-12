cmake_minimum_required(VERSION 3.24)
project(PracticasDatos2)

set(CMAKE_CXX_STANDARD 17)

add_executable(PracticasDatos2 aplicacion/main.cpp aplicacion/Node.cpp aplicacion/List.h aplicacion/List.cpp aplicacion/Collector.cpp)
