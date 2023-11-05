cmake_minimum_required(VERSION 3.27.7)   # the minimal CMake version required
project(exe VERSION 0.1)   # the solution name

set(CMAKE_CXX_STANDARD 14)	 # we request C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)	# we request that CMake verifies the compiler
set(CMAKE_CXX_EXTENSIONS OFF)	 # we request -std=c++14 in the compiler  flags instead of –std=gnu++14

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./../build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "./../../build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "./../../build")


add_subdirectory(cashDesk)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PUBLIC cashDesk)
target_link_libraries(${PROJECT_NAME} PUBLIC CashDesk)
