#ifndef OBJECTIVES_CONTINUOUS_2D_BealesFunction
#define OBJECTIVES_CONTINUOUS_2D_BealesFunction

#include "../ContinuousObjective.hpp"

class BealesFunction : public ContinuousObjective {
	public:
	BealesFunction();
	float checkFitness(Genome* genome);
};

#endif
