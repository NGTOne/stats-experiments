#ifndef OBJECTIVES_CONTINUOUS_ND_StyblinskiTangFunction
#define OBJECTIVES_CONTINUOUS_ND_StyblinskiTangFunction

#include "../ContinuousObjective.hpp"

class StyblinskiTangFunction : public ContinuousObjective {
	public:
	StyblinskiTangFunction(unsigned int genomeLength);
	float checkFitness(Genome* genome);
};

#endif
