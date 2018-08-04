cmake_minimum_required (VERSION 2.8)
#project name
PROJECT(strategy_pattern)

ADD_DEFINITIONS(-std=c++11)

AUX_SOURCE_DIRECTORY(./source DIR_SRCS)

ADD_EXECUTABLE(strategy ${DIR_SRCS})
