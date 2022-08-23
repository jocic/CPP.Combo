cmake_minimum_required(VERSION 3.5)

project(untitled LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(combo src/combo.h src/combo.cpp src/main.cpp)

install(TARGETS combo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
