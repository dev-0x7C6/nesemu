cmake_minimum_required(VERSION 3.16)

project(nesemu VERSION 0.0.1 LANGUAGES CXX)

find_package(GTest)
include(FindPkgConfig)
pkg_check_modules(BENCHMARK REQUIRED IMPORTED_TARGET benchmark)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(nesemu
	instructions.hpp
	main.cpp
	opcodes.hpp
	registers.hpp
)

add_executable(nesemu-tests
	ut/instruction-tests.cpp
	ut/main.cpp
)

target_link_libraries(nesemu-tests
	GTest::GTest
)

add_executable(nesemu-benchmark
	benchmark/main.cpp
)

target_link_libraries(nesemu-benchmark
	PkgConfig::BENCHMARK
)
