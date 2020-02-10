# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("launcher")

# Include sub-projects.
# curl settings
# libcurl - cmake .. -G "NMake Makefiles" -DHTTP_ONLY=ON -DBUILD_TESTING=OFF -DBUILD_CURL_EXE=OFF -DUSE_OPENSSL=ON

option(LIBRESSL_APPS "Build apps" OFF)
option(LIBRESSL_TESTS OFF)

add_subdirectory ("libressl")
add_subdirectory ("curl")
add_subdirectory ("zip")
add_subdirectory ("cjson")
add_subdirectory ("launcher")
