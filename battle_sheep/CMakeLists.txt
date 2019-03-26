cmake_minimum_required (VERSION 3.0)

project(hazardous-materials)

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
)



include_directories(include)
add_executable(materials src/main.cpp  ${SHARED_SOURCES})

set(
        TEST_SHARED
        test/src/engine_test.cpp
        test/src/square_test.cpp
        test/src/skill_test.cpp
        test/src/grid_test.cpp
        test/src/client_message_test.cpp
        test/src/server_message_test.cpp
        test/src/score_test.cpp
)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} test/include)
add_executable( runUnitTests test/mainTest.cpp ${TEST_SHARED} ${SHARED_SOURCES})
target_link_libraries(runUnitTests gtest gtest_main pthread)
add_test( runUnitTests runUnitTests )