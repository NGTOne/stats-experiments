#include "objectives/continuous/n-d/RosenbrockFunction.hpp"
#include <math.h>

float RosenbrockFunction::checkFitness(Genome* genome) {
	float total = 0;
	for (unsigned int i = 0; i < this->genomeLength - 1; i++)
		total += (
			100 *
			pow(
				genome->getIndex<double>(i + 1) -
				pow(genome->getIndex<double>(i), 2), 2
			) +
			pow(genome->getIndex<double>(i) - 1, 2)
		);

	return -total;
}
