#include "objectives/continuous/n-d/GriewankFunction.hpp"
#include <math.h>

float GriewankFunction::checkFitness(Genome* genome) {
	double sum = 0.0;
	double product = 1.0;
	for (unsigned int i = 0; i < this->genomeLength; i++) {
		double value = genome->getIndex<double>(i);
		sum += pow(value, 2);
		product *= cos(value/sqrt((double)i+1.0));
	}
	return -(1.0 + (1.0/4000.0) * sum - product);
}
