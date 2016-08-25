#ifndef OBJECTIVES_DISCRETE_BINARY_LongestFragmentFunction
#define OBJECTIVES_DISCRETE_BINARY_LongestFragmentFunction

#include "BinaryObjective.hpp"

class LongestFragmentFunction: public BinaryObjective {
	public:
	LongestFragmentFunction(unsigned int genomeLength);
	float checkFitness(Genome* genome);
};

#endif
