#ifndef OBJECTIVES_DISCRETE_BINARY_H_IFFFunction
#define OBJECTIVES_DISCRETE_BINARY_H_IFFFunction

#include "BinaryObjective.hpp"

class H_IFFFunction: public BinaryObjective {
	private:
	unsigned int base;

	unsigned int checkChunks(unsigned int chunkPower, Genome* genome);

	public:
	H_IFFFunction(unsigned int genomeLength, unsigned int base = 2);
	float checkFitness(Genome* genome);
};

#endif
