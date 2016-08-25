#ifndef OBJECTIVES_DISCRETE_BINARY_LeadingOnesFunction
#define OBJECTIVES_DISCRETE_BINARY_LeadingOnesFunction

#include "BinaryObjective.hpp"

class LeadingOnesFunction: public BinaryObjective {
	public:
	LeadingOnesFunction(unsigned int genomeLength);
	float checkFitness(Genome* genome);
};

#endif
