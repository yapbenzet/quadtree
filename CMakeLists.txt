cmake_minimum_required (VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
project(quadtree)

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/include/node.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/point.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/quad_tree.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/region.hpp
)

add_executable(quadtree ${SOURCE} ${HEADERS})


