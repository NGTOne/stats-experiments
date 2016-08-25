#ifndef StatsExperiment_H
#define StatsExperiment_H

#include <libHierGA/HierGA.hpp>
#include "objectives/ExperimentObjective.hpp"

class StatsExperiment {
	private:
	HierarchicalEA* ea;

	public:
	StatsExperiment(
		unsigned int populationSize,
		ExperimentObjective* objective,
		EvolutionarySystem* system,
		std::string filePrefix,
		unsigned int runNumber,
		double targetFitness,
		double epsilon,
		unsigned int numEpochs = 100
	);
	~StatsExperiment();

	void run();
};

#endif
