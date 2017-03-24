#include "objectives/discrete/binary/AverageFragmentFunction.hpp"

AverageFragmentFunction::AverageFragmentFunction(
	unsigned int genomeLength
) : BinaryObjective(genomeLength) {}

float AverageFragmentFunction::checkFitness(Genome* genome) {
	unsigned int totalLength = 0;
	unsigned int numFragments = 0;
	unsigned int currentLength = 0;

	for (unsigned int i = 0; i < this->genomeLength; i++) {
		unsigned int val = genome->getIndex<unsigned int>(i);
		if (val == 1) {
			currentLength += 1;
		} else {
			if (currentLength > 0) numFragments++;
			totalLength += currentLength;
			currentLength = 0;
		}
	}

	if (currentLength > 0) numFragments++;
	totalLength += currentLength;

	return (float)totalLength/(float)numFragments;
}
