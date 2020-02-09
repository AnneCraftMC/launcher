# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("launcher")

# Include sub-projects.
# libcurl - cmake .. -G "NMake Makefiles" -DHTTP_ONLY=ON -DBUILD_TESTING=OFF -DBUILD_CURL_EXE=OFF
option(HTTP_ONLY ON)
option(BUILD_CURL_EXE OFF)
option(BUILD_TESTING OFF)
option(USE_OPENSSL ON)

option(LIBRESSL_APPS "Build apps" OFF)
option(LIBRESSL_TESTS OFF)

add_subdirectory ("libressl")
add_subdirectory ("curl")
add_subdirectory ("launcher")
