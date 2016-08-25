#ifndef OBJECTIVES_CONTINUOUS_2D_BoothsFunction
#define OBJECTIVES_CONTINUOUS_2D_BoothsFunction

#include "../ContinuousObjective.hpp"

class BoothsFunction : public ContinuousObjective {
	public:
	BoothsFunction();
	float checkFitness(Genome* genome);
};

#endif
