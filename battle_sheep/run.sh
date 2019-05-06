#!/bin/sh

[ $# -eq 1 ] && { type=$1 ; } || { type="debug" ; }


cd $(dirname $( realpath "$0" ) )

# Creating build directory if needed
[ -d "build" ] || mkdir build
cd build
valgrind --track-origins=yes --leak-check=full ./server >server.out 2>servererr.out & valgrind --track-origins=yes --leak-check=full ./client localhost 8080 >client1.out 2>client1err.out & valgrind --track-origins=yes --leak-check=full ./client localhost 8080 >client2.out 2>client2err.out & valgrind --track-origins=yes --leak-check=full ./client localhost 8080 >client3.out 2>client3err.out & valgrind --track-origins=yes --leak-check=full ./client localhost 8080 >client4.out 2>client4err.out && cd ..

