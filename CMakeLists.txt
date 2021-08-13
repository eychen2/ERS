cmake_minimum_required(VERSION 3.19)
project(ERS)

set(CMAKE_CXX_STANDARD 14)

add_executable(ERS main.cpp player.cpp player.h card.h deck.h deck.cpp card.cpp)