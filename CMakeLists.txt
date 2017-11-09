cmake_minimum_required(VERSION 2.8)
project(opencv_multitracker)

find_package(OpenCV REQUIRED)
include_directories(include ${OpenCV_INCLUDE_DIRS})

add_executable(multitracker src/multitracker.cpp src/KCFTracker.cpp)
target_Link_Libraries(multitracker ${OpenCV_LIBS})