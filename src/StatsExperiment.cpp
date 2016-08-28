#include "StatsExperiment.hpp"
#include <sstream>

StatsExperiment::StatsExperiment(
	unsigned int populationSize,
	ExperimentObjective* objective,
	EvolutionarySystem* system,
	std::string filePrefix,
	unsigned int runNumber,
	double targetFitness,
	double epsilon,
	unsigned int numEpochs
) {
	this->ea = new HierarchicalEA(numEpochs);
	this->ea->addNode<EANode>(
		populationSize,
		objective->getLoci(),
		std::vector<ObjectiveFunction*>({objective}),
		objective->getToString(),
		std::vector<EndCondition*>({}),
		"P1",
		true,
		true,
		system
	);

	this->ea->setEvolutionOrder({"P1"});

	this->filePrefix = filePrefix;
	this->runNumber = runNumber;

	this->addInstrument<GenerationBestFitnessCSV>(
		"best-fitnesses",
		".csv"
	);
}

StatsExperiment::~StatsExperiment() {
	this->ea->deleteAllNodes();
	delete(this->ea);
}

void StatsExperiment::run() {
	this->ea->run(false);
}
