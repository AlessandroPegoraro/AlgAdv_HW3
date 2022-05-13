cmake_minimum_required(VERSION 3.14)
project(AlgAdvHW3)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgAdvHW3 main.cpp algorithms/karger.h algorithms/karger_early_stop.h algorithms/karger_timeout.h utilities/Parser.h utilities/Graph_Data.h subroutines/full_contraction.h)