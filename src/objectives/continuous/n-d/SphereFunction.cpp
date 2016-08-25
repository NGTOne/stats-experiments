#include "objectives/continuous/n-d/SphereFunction.hpp"

SphereFunction::SphereFunction(
	unsigned int genomeLength,
	double bottomVal,
	double topVal
) : ExperimentObjective(genomeLength) {
	this->bottomVal = bottomVal;
	this->topVal = topVal;
}

float SphereFunction::checkFitness(Genome* genome) {
	float total = 0;
	for (unsigned int i = 0; i < this->genomeLength; i++)
		total += genome->getIndex<double>(i);
	return -total;
}

std::vector<Locus*> SphereFunction::getLoci() {
	return std::vector<Locus*>(
		this->genomeLength,
		new NumericSetLocus<double>(this->bottomVal, this->topVal)
	);
}

ToStringFunction* SphereFunction::getToString() {
	return new ExperimentToString<double>(this->genomeLength);
}
