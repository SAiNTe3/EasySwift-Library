cmake_minimum_required(VERSION 3.12)

project(EasySwiftLibrary)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FILES "src/*.cpp" "src/BasicShape/*.cpp")

include_directories(
	SYSTEM ${CMAKE_SOURCE_DIR}/include
	SYSTEM ${CMAKE_SOURCE_DIR}/include/BasicShape
)

add_library(esl STATIC ${SRC_FILES})