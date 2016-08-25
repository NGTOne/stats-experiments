#ifndef OBJECTIVES_CONTINUOUS_ND_RastriginFunction
#define OBJECTIVES_CONTINUOUS_ND_RastriginFunction

#include "../ContinuousObjective.hpp"

class RastriginFunction : public ContinuousObjective {
	public:
	RastriginFunction(unsigned int genomeLength);
	float checkFitness(Genome* genome);
};

#endif
