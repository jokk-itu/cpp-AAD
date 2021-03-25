cmake_minimum_required(VERSION 3.16)

set(This datastructures_lib)
project(${This})

set(CMAKE_CXX_STANDARD 20)

set(Headers
        src/Spatial/QuadTree.h
        src/Helpers/Point2D.h
        src/Helpers/BoundingBox.h
        src/Queues/BinomialHeap.h)

set(Sources
        src/Spatial/QuadTree.tpp
        src/Exceptions/PointNotWithinBoxException.cpp
        src/Exceptions/BoxOutOfBoundsException.cpp
        src/Exceptions/BoxPositionIsNotSupportedException.cpp
        src/Helpers/Point2D.cpp
        src/Helpers/BoundingBox.cpp
        src/Helpers/BoxPosition.cpp
        src/Queues/BinomialHeap.cpp
        )

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(tests)