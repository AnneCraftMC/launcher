# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("AnneCraftLauncher")

# Include sub-projects.
# libcurl - cmake .. -G "NMake Makefiles" -DHTTP_ONLY=ON -DBUILD_TESTING=OFF -DBUILD_CURL_EXE=OFF
option(HTTP_ONLY ON)
option(BUILD_CURL_EXE OFF)
option(BUILD_TESTING OFF)
#option(CMAKE_USE_WINSSL ON)
#option(SSL_ENABLED ON)

add_subdirectory ("curl-7.68.0")
add_subdirectory ("AnneCraftLauncher")
