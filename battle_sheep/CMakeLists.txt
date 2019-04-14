cmake_minimum_required (VERSION 3.0)

project(hazardous-materials)

option(USE_STANDALONE_ASIO "set ON to use standalone Asio instead of Boost.Asio" OFF)
option(BUILD_TESTING "set ON to build library tests" OFF)

#add_compile_options(-std=c++11 -Wall -Wextra -Wsign-conversion)
add_compile_options(-lboost_system)
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

)



include_directories(include)

add_executable(server src/main_server.cpp ${SHARED_SOURCES})
add_executable(test_main src/main_test.cpp ${SHARED_SOURCES})
add_executable(client src/main_client.cpp ${SHARED_SOURCES})
target_link_libraries(server simple-websocket-server)
target_link_libraries(client simple-websocket-server)
target_link_libraries(test_main simple-websocket-server)


set(
        TEST_SHARED
        test/src/engine_test.cpp
        test/src/square_test.cpp
        test/src/skill_test.cpp
        test/src/grid_test.cpp
        test/src/client_message_test.cpp
        test/src/server_message_test.cpp
        test/src/score_test.cpp
        src/GameScheduler.cpp

)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} test/include simple_web_socket/include )
add_executable( runUnitTests test/mainTest.cpp ${TEST_SHARED} ${SHARED_SOURCES} )
target_link_libraries(runUnitTests gtest gtest_main pthread)
add_test( runUnitTests runUnitTests )