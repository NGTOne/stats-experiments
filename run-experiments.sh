#!/bin/bash

# Mandatory argument; run each experiment this many times
count=$1
shift

for experiment in $(find experiments-to-run -type f)
do
	exper=${experiment/experiments-to-run\//}

	for i in $(seq 1 $count)
	do
		echo -n "Running $exper... $i/$count"
		if [[ $i -ne $count ]]
		then
			echo -n R | tr 'R' '\r'
		fi
		./$experiment results/$exper/ $i > results/$exper/out-$i.txt
	done
	echo " Done"
done
