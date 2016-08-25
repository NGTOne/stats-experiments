#include "objectives/discrete/binary/LOTZFunction.hpp"

LOTZFunction::LOTZFunction(
	unsigned int genomeLength
) : BinaryObjective(genomeLength) {}

float LOTZFunction::checkFitness(Genome* genome) {
	unsigned int total = 0;

	for (unsigned int i = 0; i < this->genomeLength; i++) {
		unsigned int val = genome->getIndex<unsigned int>(i);
		if (val == 1) total += 1; else break;
	}

	for (
		unsigned int i = this->genomeLength-1;
		i < this->genomeLength;
		i--
	) {
		unsigned int val = genome->getIndex<unsigned int>(i);
		if (val == 0) total += 1; else break;
	}

	return total;
}
