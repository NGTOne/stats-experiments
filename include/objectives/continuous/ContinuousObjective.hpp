#ifndef OBJECTIVES_CONTINUOUS_ContinuousObjective
#define OBJECTIVES_CONTINUOUS_ContinuousObjective

#include "../ExperimentObjective.hpp"

class ContinuousObjective: public ExperimentObjective {
	protected:
	double bottomVal;
	double topVal;

	public:
	ContinuousObjective(
		unsigned int genomeLength,
		double bottomVal,
		double topVal
	);

	virtual std::vector<Locus*> getLoci();
	virtual ToStringFunction* getToString();
};

#endif
