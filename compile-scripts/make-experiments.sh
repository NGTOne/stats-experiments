#!/bin/bash -ex

rm -rf experiments-to-run results
mkdir experiments-to-run results

if [[ "$(uname -s)" == "Linux" ]]
then
	EIGEN="/usr/include/eigen3"
	SHARED="-lHierGA"
elif [[ "$(uname -s)" == "Darwin" ]]
then
	EIGEN="/usr/local/include/eigen3"
	SHARED="-L/usr/local/lib -lHierGA"
fi

for experiment in $(find src/experiments/* -print | egrep "pp$")
do
	dirname=${experiment/src\/experiments\//}
	dirname=${dirname/\.cpp/}
	#targetDir=${dirname/\/[^/]+/}
	targetDir=$(echo "$dirname" | sed 's/\/[^/]\+$//')

	mkdir -p experiments-to-run/$targetDir
	g++ -c -g -Wall -std=gnu++0x -Iinclude -I/usr/local/include -I$EIGEN $experiment -o obj/experiments/$dirname.o
	g++ -o experiments-to-run/$dirname obj/experiments/$dirname.o obj/StatsExperiment.o $(find obj/objectives -name "*.o") $SHARED
done
