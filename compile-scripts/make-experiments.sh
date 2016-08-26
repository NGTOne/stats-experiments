#!/bin/bash -ex

rm -rf experiments results
mkdir experiments results

if [[ "$(uname -s)" == "Linux" ]]
then
	EIGEN="/usr/include/eigen3"
elif [[ "$(uname -s)" == "Darwin" ]]
then
	EIGEN="/usr/local/include/eigen3"
fi

for experiment in $(find src/experiments/* -print | egrep "pp$")
do
	dirname=$(echo "$experiment" | sed 's/src\/experiments\/|\.cpp$//g')

	g++ -c -g -Wall -std=gnu++0x -Iinclude -I/usr/local/include -I$EIGEN $experiment -o obj/experiments/$dirname.o
	g++ -o experiments/$dirname obj/experiments/$dirname.o obj/StatsExperiment.o $(find obj/objectives -name "*.o")
done
