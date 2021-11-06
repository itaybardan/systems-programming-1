# cmake_minimum_required(VERSION <specify CMake version here>)
project(system_programming_assignment_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(system_programming_assignment_1
        include/Action.h
        include/Customer.h
        src/main.cpp
        include/Studio.h
        include/Trainer.h
        include/Workout.h)
