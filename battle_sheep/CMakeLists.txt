cmake_minimum_required (VERSION 3.0)

project(hazardous-materials)

set (
        SHARED_SOURCES
        src/Square.cpp
        src/Engine.cpp
        src/Skill.cpp
        src/Grid.cpp
        src/FactorySkill.cpp
)



include_directories(include)
add_executable(materials src/main.cpp  ${SHARED_SOURCES})

set(
        TEST_SHARED
        test/test1.cpp
)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable( runUnitTests test/mainTest.cpp ${TEST_SHARED} ${SHARED_SOURCES})
target_link_libraries(runUnitTests gtest gtest_main)
add_test( runUnitTests runUnitTests )