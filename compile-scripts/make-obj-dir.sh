#!/bin/bash

rm -rf obj
mkdir obj

for dir in $(find src/* -print | sed 's/src\///g' | egrep -v "pp$")
do
	dir=$(echo $dir | sed 's/src\/\?//')
	mkdir obj/$dir
done
