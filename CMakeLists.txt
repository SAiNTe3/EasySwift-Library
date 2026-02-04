cmake_minimum_required(VERSION 3.12)

project(EasySwiftLibrary)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FILES 
	"src/ESL/*.cpp" 
	"src/ESL/BasicShape/*.cpp" 
	"src/glad/glad.c"
	"src/ESL/Widget/*.cpp"
)

include_directories(
	SYSTEM ${CMAKE_SOURCE_DIR}/include
	SYSTEM ${CMAKE_SOURCE_DIR}/include/ESL
	SYSTEM ${CMAKE_SOURCE_DIR}/include/ESL/BasicShape
	SYSTEM ${CMAKE_SOURCE_DIR}/include/ESL/Widget
	SYSTEM ${CMAKE_SOURCE_DIR}/include/freetype
)

add_library(esl STATIC ${SRC_FILES})