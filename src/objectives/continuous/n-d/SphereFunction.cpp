#include "objectives/continuous/n-d/SphereFunction.hpp"
#include <math.h>

float SphereFunction::checkFitness(Genome* genome) {
	float total = 0;
	for (unsigned int i = 0; i < this->genomeLength; i++)
		total += pow(genome->getIndex<double>(i), 2);
	return -total;
}
