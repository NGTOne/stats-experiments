#include "objectives/discrete/binary/LongestFragmentFunction.hpp"

LongestFragmentFunction::LongestFragmentFunction(
	unsigned int genomeLength
) : BinaryObjective(genomeLength) {}

float LongestFragmentFunction::checkFitness(Genome* genome) {
	unsigned int longest = 0;
	unsigned int current = 0;

	for (unsigned int i = 0; i < this->genomeLength; i++) {
		unsigned int val = genome->getIndex<unsigned int>(i);
		if (val == 1) current += 1; else current = 0;
		if (current > longest) longest = current;
	}

	return longest;
}
