cmake_minimum_required(VERSION 3.0)
project(RoutingAlgorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(RoutingAlgorithms src/main/main.c include/ip.h src/components/ip.c src/routing/link_state.c)
