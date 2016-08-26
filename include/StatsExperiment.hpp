#ifndef StatsExperiment_H
#define StatsExperiment_H

#include <libHierGA/HierGA.hpp>
#include "objectives/ExperimentObjective.hpp"

class StatsExperiment {
	private:
	HierarchicalEA* ea;
	std::string filePrefix;
	unsigned int runNumber;

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

	template <typename InstrType, typename... params>
	void addInstrument(
		std::string fileInfix,
		std::string fileSuffix,
		params... as
	);
};

template <typename InstrType, typename... params>
void StatsExperiment::addInstrument(
	std::string fileInfix,
	std::string fileSuffix,
	params... as
) {
	std::stringstream ss;
	ss << this->filePrefix << fileInfix <<
		"-" << this->runNumber << fileSuffix;

	this->ea->addPopulationInstrumentation<InstrType>(
		"P1",
		ss.str(),
		as...
	);
}

#endif
