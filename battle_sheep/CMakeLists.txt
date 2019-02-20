cmake_minimum_required (VERSION 3.0)

project (Battle_Sheep )


# Set version number
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)

# All source file and headers
set (
	SHARED_SOURCES
	engine.cpp
	hub.cpp
	interface.cpp
	player.cpp
	skill.cpp
	square.cpp
	)

# Header files
include_directories(include)

# The two executable files
add_executable(server server.cpp server.h ${SHARED_SOURCES} ${SHARED_HEADERS})

add_executable(client client.cpp client.h ${SHARED_SOURCES} ${SHARED_HEADERS})

