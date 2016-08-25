#ifndef OBJECTIVES_CONTINUOUS_ND_RosenbrockFunction
#define OBJECTIVES_CONTINUOUS_ND_RosenbrockFunction

#include "../ContinuousObjective.hpp"

class RosenbrockFunction : public ContinuousObjective {
	public:
	using ContinuousObjective::ContinuousObjective;
	float checkFitness(Genome* genome);
};

#endif
