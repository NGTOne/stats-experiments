#ifndef OBJECTIVES_DISCRETE_BINARY_LOTZFunction
#define OBJECTIVES_DISCRETE_BINARY_LOTZFunction

#include "BinaryObjective.hpp"

class LOTZFunction: public BinaryObjective {
	public:
	LOTZFunction(unsigned int genomeLength);
	float checkFitness(Genome* genome);
};

#endif
