#include "objectives/continuous/n-d/RosenbrockFunction.hpp"
#include <math.h>

float RosenbrockFunction::checkFitness(Genome* genome) {
	float total = 0;
	for (unsigned int i = 0; i < this->genomeLength - 1; i++) {
		double x = genome->getIndex<double>(i);
		double xp1 = genome->getIndex<double>(i + 1);
		total += 100*pow(xp1 - pow(x, 2), 2) + pow(x - 1, 2);
	}

	return -total;
}
