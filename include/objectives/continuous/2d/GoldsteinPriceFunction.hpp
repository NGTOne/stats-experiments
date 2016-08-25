#ifndef OBJECTIVES_CONTINUOUS_2D_GoldsteinPriceFunction
#define OBJECTIVES_CONTINUOUS_2D_GoldsteinPriceFunction

#include "../ContinuousObjective.hpp"

class GoldsteinPriceFunction : public ContinuousObjective {
	public:
	GoldsteinPriceFunction();
	float checkFitness(Genome* genome);
};

#endif
