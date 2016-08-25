#ifndef OBJECTIVES_CONTINUOUS_ND_SphereFunction
#define OBJECTIVES_CONTINUOUS_ND_SphereFunction

#include "../ContinuousObjective.hpp"

class SphereFunction : public ContinuousObjective {
	public:
	using ContinuousObjective::ContinuousObjective;
	float checkFitness(Genome* genome);
};

#endif
