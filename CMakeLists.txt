cmake_minimum_required(VERSION 3.23)
project(Data_Structures_Assignment_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Structures_Assignment_2
        main.cpp
        Road.cpp Road.h
        MaxHeap.cpp MaxHeap.h
        Roads.cpp Roads.h
        BridgeNode.h
        List.cpp List.h
        General.h General.cpp)
