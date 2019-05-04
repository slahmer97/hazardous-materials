cmake_minimum_required (VERSION 3.0)

project (Battle_Sheep )

# Directory containing the cmake sfml importer
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Compiling options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall --std=c++0x")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Looking for the sfml package
find_package(SFML 2 COMPONENTS network graphics window system )



####### Part to move elsewhere
option(USE_STANDALONE_ASIO "set ON to use standalone Asio instead of Boost.Asio" OFF)
option(BUILD_TESTING "set ON to build library tests" OFF)

#add_compile_options(-std=c++11 -Wall -Wextra -Wsign-conversion)
add_compile_options(-lboost_system -lboost_thread -lthread -lpthread -lcrypto -lssl -lboost_filesystem -llog4cpp)
add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY -DBOOST_SYSTEM_NO_DEPRECATED)
add_library(simple-websocket-server INTERFACE)


find_package(Threads REQUIRED)
target_link_libraries(simple-websocket-server INTERFACE ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(simple-websocket-server INTERFACE simple_web_socket)

if(USE_STANDALONE_ASIO)
    target_compile_definitions(simple-websocket-server INTERFACE USE_STANDALONE_ASIO)
    find_file(HAVE_ASIO asio.hpp)
    if(NOT HAVE_ASIO)
        message(FATAL_ERROR "Standalone Asio not found")
    endif()
else()
    find_package(Boost 1.54.0 COMPONENTS system thread coroutine context REQUIRED)
    target_link_libraries(simple-websocket-server INTERFACE ${Boost_LIBRARIES})
    target_include_directories(simple-websocket-server INTERFACE ${Boost_INCLUDE_DIR})
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
        target_compile_definitions(simple-websocket-server INTERFACE USE_BOOST_REGEX)
        find_package(Boost 1.54.0 COMPONENTS regex REQUIRED)
        target_link_libraries(simple-websocket-server INTERFACE ${Boost_LIBRARIES})
        target_include_directories(simple-websocket-server INTERFACE ${Boost_INCLUDE_DIR})
    endif()
endif()

if(WIN32)
    target_link_libraries(simple-websocket-server INTERFACE ws2_32 wsock32)
endif()

if(APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
endif()

find_package(OpenSSL REQUIRED)
target_link_libraries(simple-websocket-server INTERFACE ${OPENSSL_LIBRARIES})
target_include_directories(simple-websocket-server INTERFACE ${OPENSSL_INCLUDE_DIR})

#### End of part to move elsewhere


# The common sources between client and server
set(
        SHARED_SOURCES
        src/Square.cpp
        src/Engine.cpp
        src/Skill.cpp
        src/Grid.cpp
        src/FactorySkill.cpp
        src/ServerMessage.cpp
        src/ClientMessage.cpp
        src/Score.cpp
        src/Player.cpp
        src/Game.cpp
        src/GameScheduler.cpp
        src/Team.cpp
        src/FactoryEngine.cpp
        src/ClientMessageSender.cpp

)

# the client_only sources
set (
	CLIENT_ONLY_SOURCES
	src/interface.cpp
	src/button.cpp
	src/game_menu.cpp
	src/b_switch.cpp
	src/textfield.cpp
	src/display_grid.cpp
	src/texture_manager.cpp
	src/textarea.cpp
	)

# the server only sources
set (
	SERVER_ONLY_SOURCES
	)

# Header files
include_directories(include)

# The executables files
# The old server, now hosted in main_server.h
#add_executable(server src/server.cpp include/server.h ${SHARED_SOURCES} ${SERVER_ONLY_SOURCES})


# We compile the client only if sfml was found
if(${SFML_FOUND})
	# We need to include the .h for sfml
	include_directories(${SFML_INCLUDE_DIR})
	# The executable for the client itself
	add_executable(client src/client.cpp ${CLIENT_ONLY_SOURCES} ${SHARED_SOURCES} )
	# Library linking
	target_link_libraries(client simple-websocket-server pthread)
	target_link_libraries(client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
	
	# We copy the assets directory, containing the textures and font for the game
	file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

else()
	message("Compiling the client require the sfml library")
	message("Check https://www.sfml-dev.org for more information")
endif()



# The server itself
add_executable(server src/main_server.cpp  ${SHARED_SOURCES} ${SERVER_ONLY_SOURCES})
# The main used for testing
add_executable(test_main src/main_test.cpp ${SHARED_SOURCES})
# The CLI client to test the server
add_executable(client_test src/main_client.cpp ${SHARED_SOURCES})


#Library linking
target_link_libraries(server simple-websocket-server pthread)
target_link_libraries(test_main simple-websocket-server pthread)
target_link_libraries(client_test simple-websocket-server pthread)


# The test source files
set(
	TEST_SRC
        # src/Square.cpp
        # src/Engine.cpp
        # src/Skill.cpp
        # src/Grid.cpp
        # src/FactorySkill.cpp
        test/src/engine_test.cpp
        test/src/square_test.cpp
        test/src/skill_test.cpp
        test/src/grid_test.cpp
        test/src/client_message_test.cpp
        test/src/server_message_test.cpp
        test/src/score_test.cpp
        #src/GameScheduler.cpp

)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} test/include simple_web_socket/include )
add_executable( runUnitTests test/mainTest.cpp ${TEST_SRC} ${SHARED_SOURCES} )
target_link_libraries(runUnitTests gtest gtest_main simple-websocket-server pthread)
add_test( runUnitTests runUnitTests )
