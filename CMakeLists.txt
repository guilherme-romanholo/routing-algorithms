cmake_minimum_required(VERSION 3.0)
project(RoutingAlgorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(RoutingAlgorithms src/main/main.c include/ip.h src/components/ip.c include/link_state.h src/routing/link_state.c include/package.h src/components/package.c include/graph.h src/graph/graph.c include/distance_vector.h src/routing/distance_vector.c src/routing/distance_vector.c data/graph_1.txt src/main/main.c)
