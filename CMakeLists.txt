cmake_minimum_required(VERSION 3.9)
project(Group_Program)

set(CMAKE_CXX_STANDARD 11)

add_executable(Group_Program main.cpp rsvp.h person.h rsvp.cpp person.cpp)