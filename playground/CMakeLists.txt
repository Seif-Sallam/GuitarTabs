cmake_minimum_required(VERSION 3.16)

add_executable(GuitarTabs-Playground
	main.cpp
)

target_link_libraries(GuitarTabs-Playground
	PRIVATE
	GuitarTabs
)

target_include_directories(GuitarTabs-Playground
	PRIVATE
		./../guitar-tabs/include
)
