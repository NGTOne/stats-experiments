#include "StatsExperiment.hpp"

StatsExperiment::StatsExperiment(
	unsigned int populationSize,
	ExperimentObjective* objective,
	EvolutionarySystem* system,
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
}

StatsExperiment::~StatsExperiment() {
	this->ea->deleteAllNodes();
	delete(this->ea);
}

void StatsExperiment::run() {
	this->ea->run(true);
}
