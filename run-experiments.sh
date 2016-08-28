#!/bin/bash

# Mandatory argument; run each experiment this many times
count=$1
shift

# Mandatory argument; run this many experiments concurrently
threads=$1
shift

for experiment in $(find experiments-to-run -type f)
do
	exper=${experiment/experiments-to-run\//}
	experCount=0

	for i in $(seq 1 $(($count/3)))
	do
		for k in $(seq 1 $threads)
		do
			experCount=$(($experCount + 1))
			echo "Running $exper $experCount"
			./$experiment results/$exper/ $experCount > /dev/null &
		done

		for job in $(jobs -p)
		do
			wait $job
		done
	done
done

perl collate-results.pl
