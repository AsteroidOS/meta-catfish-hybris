cmake_minimum_required(VERSION 3.21)
project(synclcdtime C)

set(CMAKE_C_STANDARD 17)

add_executable(synclcdtime synclcdtime.c)
install(TARGETS synclcdtime DESTINATION bin)
