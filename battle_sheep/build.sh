#!/bin/sh


cd $(dirname $( realpath "$0" ) )

# Creating build directory if needed
[ -d "build" ] || mkdir build
cd build
cmake .. && make

