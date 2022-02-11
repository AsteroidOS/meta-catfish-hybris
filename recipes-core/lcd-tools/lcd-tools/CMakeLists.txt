cmake_minimum_required(VERSION 3.21)
project(lcd-tools VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third-party/cxxopts)

find_package(PkgConfig REQUIRED)
pkg_search_module(LIBHYBRIS REQUIRED hybris-egl-platform)

add_executable(lcd-tools lcd-tools.cpp lcd-sync-time.cpp)
target_link_libraries(lcd-tools PUBLIC cxxopts ${LIBHYBRIS_LIBRARIES})
install(TARGETS lcd-tools DESTINATION bin)
