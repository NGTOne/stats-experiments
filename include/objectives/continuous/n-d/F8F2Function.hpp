#ifndef OBJECTIVES_CONTINUOUS_ND_F8F2Function
#define OBJECTIVES_CONTINUOUS_ND_F8F2Function

#include "../ContinuousObjective.hpp"

class F8F2Function : public ContinuousObjective {
	private:
	double F2(double x, double y);
	double F8(double x);

	public:
	F8F2Function(unsigned int genomeLength);
	float checkFitness(Genome* genome);
};

#endif
