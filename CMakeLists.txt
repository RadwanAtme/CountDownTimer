cmake_minimum_required(VERSION 3.15)
project(Countdown)

set(CMAKE_CXX_STANDARD 17)

add_executable(Countdown main.cpp Date.cpp CountDownTimer.cpp)