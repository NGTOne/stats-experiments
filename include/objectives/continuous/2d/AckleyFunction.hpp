#ifndef OBJECTIVES_CONTINUOUS_2D_AckleyFunction
#define OBJECTIVES_CONTINUOUS_2D_AckleyFunction

#include "../ContinuousObjective.hpp"

class AckleyFunction : public ContinuousObjective {
	public:
	AckleyFunction();
	float checkFitness(Genome* genome);
};

#endif
