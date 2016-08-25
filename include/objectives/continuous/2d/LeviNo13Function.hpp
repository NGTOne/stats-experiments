#ifndef OBJECTIVES_CONTINUOUS_2D_LeviNo13Function
#define OBJECTIVES_CONTINUOUS_2D_LeviNo13Function

#include "../ContinuousObjective.hpp"

class LeviNo13Function : public ContinuousObjective {
	public:
	LeviNo13Function();
	float checkFitness(Genome* genome);
};

#endif
