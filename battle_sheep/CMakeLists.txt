cmake_minimum_required(VERSION 3.13)
project(hazardous-materials)

set (
        SHARED_SOURCES
        src/Square.cpp
        src/Engine.cpp
        src/Grid.cpp
        src/Skill.cpp
        src/FactorySkill.cpp
)


include_directories(include)
add_executable(materials src/main.cpp  ${SHARED_SOURCES})