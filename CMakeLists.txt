cmake_minimum_required(VERSION 3.20)
project(MyGame)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(SOURCE src/Creature.cpp
        src/Protagonist.cpp
        src/Enemy.cpp)

add_executable(${PROJECT_NAME}
        main.cpp
        ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC
        ${SDL2_INCLUDE_DIRS}
        ${SDL2IMAGE_INCLUDE_DIRS}
        include)

target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES})