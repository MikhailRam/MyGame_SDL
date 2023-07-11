cmake_minimum_required(VERSION 3.20)
project(MyGame)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

add_executable(MyGame main.cpp)

include_directories(MyGame ${SDL2_INCLUDE_DIRS})
target_link_libraries(MyGame ${SDL2_LIBRARIES})