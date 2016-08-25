#include "objectives/discrete/binary/LeadingOnesFunction.hpp"

LeadingOnesFunction::LeadingOnesFunction(
	unsigned int genomeLength
) : BinaryObjective(genomeLength) {}

float LeadingOnesFunction::checkFitness(Genome* genome) {
	unsigned int total;

	for (unsigned int i = 0; i < this->genomeLength; i++) {
		unsigned int val = genome->getIndex<unsigned int>(i);
		if (val == 1) total += 1; else break;
	}

	return total;
}
