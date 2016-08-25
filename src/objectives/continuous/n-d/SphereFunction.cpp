#include "objectives/continuous/n-d/SphereFunction.hpp"

float SphereFunction::checkFitness(Genome* genome) {
	float total = 0;
	for (unsigned int i = 0; i < this->genomeLength; i++)
		total += genome->getIndex<double>(i);
	return -total;
}
