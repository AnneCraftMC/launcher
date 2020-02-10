cmake_minimum_required (VERSION 3.8)

add_executable(launcher "launcher.c" "JREDownloader.c")

target_link_libraries(launcher libcurl)
target_link_libraries(launcher zip)
target_link_libraries(launcher cjson)