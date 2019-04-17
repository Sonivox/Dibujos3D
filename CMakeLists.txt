cmake_minimum_required(VERSION 3.13)
project(Desing3D)

set(CMAKE_CXX_STANDARD 14)

add_executable(Desing3D main.cpp)


# adding GLUT lib

find_package(GLUT REQUIRED) #search for GLUT lib
include_directories(${GLUT_INCLUDE_DIRS}) # add directories
link_directories(${GLUT_LIBRARY_DIRS}) # link directories
add_definitions(${GLUT_DEFINITIONS}) #A add definitions


# adding OPENGL lib

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

# lib linking

target_link_libraries(Desing3D ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )