#ifndef OBJECTIVES_CONTINUOUS_ND_SphereFunction
#define OBJECTIVES_CONTINUOUS_ND_SphereFunction

#include "../../ExperimentObjective.hpp"

class SphereFunction : public ExperimentObjective {
	private:
	double bottomVal;
	double topVal;

	public:
	SphereFunction(
		unsigned int genomeLength,
		double bottomVal,
		double topVal
	);

	float checkFitness(Genome* genome);

	std::vector<Locus*> getLoci();
	ToStringFunction* getToString();
};

#endif
