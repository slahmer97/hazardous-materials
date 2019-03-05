cmake_minimum_required (VERSION 3.0)

project (Battle_Sheep )

# Directory containing the cmake sfml importer
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Looking for the sfml package
find_package(SFML 2 COMPONENTS network graphics window system REQUIRED)

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

# The three executables files
# The server
add_executable(server src/server.cpp include/server.h ${SHARED_SOURCES} )
target_link_libraries(server ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})


# We compile the client only if sfml was found
include_directories(${SFML_INCLUDE_DIR})
add_executable(client src/client.cpp include/client.h ${SHARED_SOURCES} )
target_link_libraries(client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})



# The testing client
add_executable(testing src/main_tmp.cpp ${SHARED_SOURCES} )
target_link_libraries(testing ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

