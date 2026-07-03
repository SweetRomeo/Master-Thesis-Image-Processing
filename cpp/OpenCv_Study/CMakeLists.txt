cmake_minimum_required(VERSION 4.0)
project(OpenCv_Study)

set(CMAKE_CXX_STANDARD 20)

set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OpenCv_Study
    main.cpp
    image_enhancement.cpp
)
target_link_libraries(OpenCv_Study ${OpenCV_LIBS})

# ---------------------------------------------------------------------------
# Google Test via FetchContent
# ---------------------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# Prevent GTest from overriding our compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ---------------------------------------------------------------------------
# Unit tests
# ---------------------------------------------------------------------------
enable_testing()

add_executable(test_image_enhancement
    test_image_enhancement.cpp
    image_enhancement.cpp
)
target_link_libraries(test_image_enhancement
    PRIVATE
    ${OpenCV_LIBS}
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_image_enhancement)
