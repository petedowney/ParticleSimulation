cmake_minimum_required(VERSION 3.19)
project(ParticleSimulation)

set(CMAKE_CXX_STANDARD 20)

#----

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 4.0.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib_cpp
            GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
            GIT_TAG v4.1.0
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# This is the main part:
add_executable(${PROJECT_NAME} src/main.cpp src/Particle/Particle.cpp src/Particle/Particle.h)
target_link_libraries(${PROJECT_NAME} raylib raylib_cpp)

# That's it! You should have an example executable that you can run. Have fun!

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()