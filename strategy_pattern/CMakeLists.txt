cmake_minimum_required (VERSION 2.8)
#project name
PROJECT(strategy_pattern)

AUX_SOURCE_DIRECTORY(./source DIR_SRCS)

ADD_EXECUTABLE(strategy ${DIR_SRCS})
