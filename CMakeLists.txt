cmake_minimum_required(VERSION 3.19)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_executable(project main.cpp file_manager.cpp file_manager.h log_manager.cpp log_manager.h)