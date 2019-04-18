cmake_minimum_required(VERSION 3.13)
project(Desing3D)

set(CMAKE_CXX_STANDARD 14)

add_executable(Desing3D main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)


add_dependencies(Desing3D OpenGL::OpenGL)

include_directories(${GLUT_INCLUDE_DIRS} )
include_directories(${GLEW_INCLUDE_DIRS} )
include_directories(${OpenGL_INCLUDE_DIRS} )


target_link_libraries(Desing3D OpenGL::OpenGL ${GLUT_LIBRARY} )
target_link_libraries(Desing3D GLEW::GLEW)