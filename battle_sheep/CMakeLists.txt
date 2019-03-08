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