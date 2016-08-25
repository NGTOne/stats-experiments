#ifndef OBJECTIVES_CONTINUOUS_ND_GriewankFunction
#define OBJECTIVES_CONTINUOUS_ND_GriewankFunction

#include "../ContinuousObjective.hpp"

class GriewankFunction : public ContinuousObjective {
	public:
	using ContinuousObjective::ContinuousObjective;
	float checkFitness(Genome* genome);
};

#endif
