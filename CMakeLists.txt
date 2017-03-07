cmake_minimum_required (VERSION 3.5)
project (AiFi)
include_directories(include)

add_executable(a 
	src/main.c 
	include/queue.h)