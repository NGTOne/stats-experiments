#ifndef OBJECTIVES_CONTINUOUS_2D_ThreeHumpCamelFunction
#define OBJECTIVES_CONTINUOUS_2D_ThreeHumpCamelFunction

#include "../ContinuousObjective.hpp"

class ThreeHumpCamelFunction : public ContinuousObjective {
	public:
	ThreeHumpCamelFunction();
	float checkFitness(Genome* genome);
};

#endif
