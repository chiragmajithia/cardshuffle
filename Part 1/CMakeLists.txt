cmake_minimum_required (VERSION 3.5)
project (AiFi)
include_directories(include)

add_executable(sol1
	src/sol1.c 
	include/queue.h)

add_executable(sol2
	src/sol2.c 
	include/queue.h)