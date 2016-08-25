#ifndef OBJECTIVES_DISCRETE_BINARY_AverageFragmentFunction
#define OBJECTIVES_DISCRETE_BINARY_AverageFragmentFunction

#include "BinaryObjective.hpp"

class AverageFragmentFunction: public BinaryObjective {
	public:
	AverageFragmentFunction(unsigned int genomeLength);
	float checkFitness(Genome* genome);
};

#endif
