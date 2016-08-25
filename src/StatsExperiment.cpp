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

	std::stringstream ss;
	ss << filePrefix << "-optimum-run" << runNumber << ".csv";
	this->ea->addPopulationInstrumentation<TargetReachedGeneration>(
		"P1",
		ss.str(),
		targetFitness,
		epsilon
	);
}

StatsExperiment::~StatsExperiment() {
	this->ea->deleteAllNodes();
	delete(this->ea);
}

void StatsExperiment::run() {
	this->ea->run(true);
}
