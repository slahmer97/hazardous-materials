#!/bin/sh



cd $(dirname $( realpath "$0" ) )

# Creating build directory if needed
[ -d "build" ] || ./build.sh
cd build
./server >server.out 2>servererr.out &
./client localhost >client1.out 2>client1err.out &
./client localhost >client2.out 2>client2err.out &
./client localhost >client3.out 2>client3err.out &
./client localhost >client4.out 2>client4err.out
wait
wait
wait
wait
