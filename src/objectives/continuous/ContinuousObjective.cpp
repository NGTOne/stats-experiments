#include "objectives/continuous/ContinuousObjective.hpp"

ContinuousObjective::ContinuousObjective(
	unsigned int genomeLength,
	double bottomVal,
	double topVal
) : ExperimentObjective(genomeLength) {
	this->bottomVal = bottomVal;
	this->topVal = topVal;
}

std::vector<Locus*> ContinuousObjective::getLoci() {
	return std::vector<Locus*>(
		this->genomeLength,
		new NumericSetLocus<double>(this->bottomVal, this->topVal)
	);
}

ToStringFunction* ContinuousObjective::getToString() {
	return new ExperimentToString<double>(this->genomeLength);
}
