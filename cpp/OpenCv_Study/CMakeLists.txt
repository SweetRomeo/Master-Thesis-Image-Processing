cmake_minimum_required(VERSION 4.0)
project(OpenCv_Study)

set(CMAKE_CXX_STANDARD 20)

set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OpenCv_Study main.cpp)

target_link_libraries(OpenCv_Study ${OpenCV_LIBS})