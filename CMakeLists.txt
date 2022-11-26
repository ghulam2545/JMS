cmake_minimum_required(VERSION 3.0)

project(JMS)

add_executable(
    out main.cpp

    # headers
    include/App.hpp
    include/User.hpp
    
    # sources
    src/App.cpp
    src/User.cpp
)