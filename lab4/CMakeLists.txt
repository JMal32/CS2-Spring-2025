cmake_minimum_required(VERSION 3.16)  # Minimum CMake version
project(MyProject)                     # Project name

set(CMAKE_CXX_STANDARD 17)              # Use C++17 standard

# Add the executable
add_executable(MyExecutable src/main.cpp)
