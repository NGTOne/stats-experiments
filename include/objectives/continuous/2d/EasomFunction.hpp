#ifndef OBJECTIVES_CONTINUOUS_2D_EasomFunction
#define OBJECTIVES_CONTINUOUS_2D_EasomFunction

#include "../ContinuousObjective.hpp"

class EasomFunction : public ContinuousObjective {
	public:
	EasomFunction();
	float checkFitness(Genome* genome);
};

#endif
