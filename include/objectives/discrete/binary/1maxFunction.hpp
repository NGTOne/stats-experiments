#ifndef OBJECTIVES_DISCRETE_BINARY_1MaxFunction
#define OBJECTIVES_DISCRETE_BINARY_1MaxFunction

#include "BinaryObjective.hpp"

class OneMaxFunction: public BinaryObjective {
	public:
	OneMaxFunction(unsigned int genomeLength);
	float checkFitness(Genome* genome);
};

#endif
