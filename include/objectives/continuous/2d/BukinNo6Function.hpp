#ifndef OBJECTIVES_CONTINUOUS_2D_BukinNo6Function
#define OBJECTIVES_CONTINUOUS_2D_BukinNo6Function

#include "../ContinuousObjective.hpp"

class BukinNo6Function : public ContinuousObjective {
	public:
	BukinNo6Function();
	float checkFitness(Genome* genome);

	std::vector<Locus*> getLoci();
};

#endif
