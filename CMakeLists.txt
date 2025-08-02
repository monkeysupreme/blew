cmake_minimum_required(VERSION 3.15)
project(blew VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optionally build shared or static library
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

find_package(SDL2 REQUIRED)
find_package(spdlog REQUIRED)

# Engine Library
add_library(blew
        src/blew.cpp
        include/blew/application.h
        include/blew/application.h
        src/application.cpp
        include/blew/window.h
        src/window.cpp
        include/blew/log.h
        src/log.cpp
        include/blew/layer.h
        include/blew/layer_stack.h
        src/layer_stack.cpp
        include/blew/layers/game_layer.h
)

# Include public headers
target_include_directories(blew
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(blew PRIVATE SDL2::SDL2)
target_link_libraries(blew PRIVATE spdlog::spdlog)

# Create examples
add_subdirectory(examples)
