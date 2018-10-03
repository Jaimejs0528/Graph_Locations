cmake_minimum_required(VERSION 3.12)
project(grafo C)

set(CMAKE_C_STANDARD 99)

add_executable(grafo main.c Library/grafo2D.c Library/grafo2D.h Library/Message/errorMessage.h)