cmake_minimum_required (VERSION 3.0)

project (Battle_Sheep )


# Set version number
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)

# All source file and headers
set (
	SHARED_SOURCES
	src/engine.cpp
	src/hub.cpp
	src/interface.cpp
	src/player.cpp
	src/skill.cpp
	src/square.cpp
	)

# Header files
include_directories(include)

# The two executable files
add_executable(server src/server.cpp include/server.h ${SHARED_SOURCES} )

add_executable(client src/client.cpp include/client.h ${SHARED_SOURCES} )

