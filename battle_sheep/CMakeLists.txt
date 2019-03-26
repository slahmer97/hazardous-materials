cmake_minimum_required (VERSION 3.0)

project (Battle_Sheep )

# Directory containing the cmake sfml importer
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Looking for the sfml package
find_package(SFML 2 COMPONENTS network graphics window system )


# All source file and headers
set (
	SHARED_SOURCES
	src/engine.cpp
	src/hub.cpp
	src/player.cpp
	src/skill.cpp
	src/square.cpp
	)

set (
	CLIENT_ONLY_SOURCES
	src/interface.cpp
	src/button.cpp
	)

set (
	SERVER_ONLY_SOURCES
	)

# Header files
include_directories(include)

# The three executables files
# The server
add_executable(server src/server.cpp include/server.h ${SHARED_SOURCES} ${SERVER_ONLY_SOURCES})


# We compile the client only if sfml was found
if(${SFML_FOUND})
	include_directories(${SFML_INCLUDE_DIR})
	add_executable(client src/client.cpp ${CLIENT_ONLY_SOURCES} ${SHARED_SOURCES} )
	target_link_libraries(client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
	
	# We copy the assets directory, containing the texture and font for the game
	file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

else()
	message("Compiling the client require the sfml library")
	message("Check https://www.sfml-dev.org for more information")
endif()


# The testing client
add_executable(testing src/main_tmp.cpp ${SHARED_SOURCES} )

