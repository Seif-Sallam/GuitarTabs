cmake_minimum_required(VERSION 3.16)

add_library(GuitarTabs
	include/MDFile.h
	include/GuitarTab.h
	src/MDFile.cpp
	src/GuitarTab.cpp
)

target_include_directories(GuitarTabs
	PRIVATE
	./
)