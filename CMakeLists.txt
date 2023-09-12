cmake_minimum_required(VERSION 3.16)

project(curvemain CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_library(curve SHARED IMPORTED)
set_target_properties(curve PROPERTIES
	IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libcurve.so"
	INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include"
)


set(SOURCES src/main.cpp)

add_executable(curvemain ${SOURCES})
target_link_libraries(curvemain curve)

