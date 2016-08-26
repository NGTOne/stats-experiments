#include "objectives/discrete/binary/H_IFFFunction.hpp"
#include <math.h>

H_IFFFunction::H_IFFFunction(
	unsigned int genomeLength,
	unsigned int base
) : BinaryObjective(genomeLength) {
	double logged = log(genomeLength)/log(base);
	if (logged != floor(logged)) throw CustomMessageException("Genome length for H-IFF must be a power of the base value (default is 2).");
	this->base = base;
}

unsigned int H_IFFFunction::checkChunks(
	unsigned int chunkPower,
	Genome* genome
) {
	unsigned int total = 0;
	unsigned int chunkSize = pow(this->base, chunkPower);

	std::vector<unsigned int> chunkVals;
	for (unsigned int i=0; i < this->genomeLength; i += chunkSize) {
		unsigned int chunkTotal = 0;
		for (unsigned int k = 0; k < chunkSize; k++)
			chunkTotal += genome->getIndex<unsigned int>(i + k);
		chunkVals.push_back(chunkTotal);

		if (chunkVals.size() == this->base) {
			unsigned int matchingChunks = 0;
			bool canAdd = true;
			for (auto chunkVal: chunkVals)
				if (chunkVal == 0 || chunkVal == chunkSize) {
					matchingChunks += chunkVal/chunkSize;
				} else {
					canAdd = false;
				}

			std::cout << matchingChunks << " ";

			if (
				canAdd &&
				matchingChunks == this->base ||
				matchingChunks == 0
			) total += chunkSize * this->base;
			chunkVals.clear();
		}
	}

	return total + (chunkSize == this->genomeLength/this->base ?
		0 : this->checkChunks(chunkPower + 1, genome));
}

float H_IFFFunction::checkFitness(Genome* genome) {
	return this->genomeLength + this->checkChunks(0, genome);
}
