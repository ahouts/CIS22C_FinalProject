cmake_minimum_required(VERSION 3.5)
project(CIS22C_FinalProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Change.cpp Change.h BST.cpp BST.h BST1.cpp BST1.h Cell.cpp Cell.h CommandLine.cpp CommandLine.h MainMenu.cpp MainMenu.h Node.cpp Node.h Node1.cpp Node1.h Refresh.cpp Refresh.h Sheet.cpp Sheet.h)
add_executable(Playground ${SOURCE_FILES})