#include "objectives/discrete/binary/1maxFunction.hpp"

OneMaxFunction::OneMaxFunction(
	unsigned int genomeLength
) : BinaryObjective(genomeLength) {}

float OneMaxFunction::checkFitness(Genome* genome) {
	unsigned int total = 0;
	for (unsigned int i = 0; i < this->genomeLength; i++)
		total += genome->getIndex<unsigned int>(i);
	return total;
}
