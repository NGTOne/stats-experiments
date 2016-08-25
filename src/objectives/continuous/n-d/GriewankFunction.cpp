#include "objectives/continuous/n-d/GriewankFunction.hpp"
#include <math.h>

float GriewankFunction::checkFitness(Genome* genome) {
	double sum = 0;
	double product = 1;
	for (unsigned int i = 0; i < this->genomeLength; i++) {
		double value = genome->getIndex<double>(i);
		sum += pow(value, 2);
		product *= cos(value/sqrt(i));
	}
	return -(1 + (1/4000) * sum - product);
}
