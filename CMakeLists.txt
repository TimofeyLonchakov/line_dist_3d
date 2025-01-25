cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)

project ("distance")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

SET(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable (distance
	${SOURCE_DIR}/point3d.cpp
	${SOURCE_DIR}/vector3d.cpp
	${SOURCE_DIR}/segment3d.cpp
	${SOURCE_DIR}/distance.cpp
)