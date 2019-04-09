#!/bin/sh

[ $# -eq 1 ] && { type=$1 ; } || { type="debug" ; }


cd $(dirname $( realpath "$0" ) )

# Creating build directory if needed
[ -d "build" ] || mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=$type .. && make

