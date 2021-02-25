cmake_minimum_required(VERSION 3.16)

project(nesmu VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(nesmu
  instructions.hpp
  main.cpp
  opcodes.hpp
  registers.hpp
)
