#ifndef OBJECTIVES_CONTINUOUS_2D_MatyasFunction
#define OBJECTIVES_CONTINUOUS_2D_MatyasFunction

#include "../ContinuousObjective.hpp"

class MatyasFunction : public ContinuousObjective {
	public:
	MatyasFunction();
	float checkFitness(Genome* genome);
};

#endif
