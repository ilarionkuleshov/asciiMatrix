cmake_minimum_required(VERSION 3.19)
project(asciiMatrix)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
