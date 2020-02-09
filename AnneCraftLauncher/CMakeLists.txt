# CMakeList.txt : CMake project for AnneCraftLauncher, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (AnneCraftLauncher "AnneCraftLauncher.c" "JREDownloader.c")
target_link_libraries(AnneCraftLauncher libcurl)

# TODO: Add tests and install targets if needed.
