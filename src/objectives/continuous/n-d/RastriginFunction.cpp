#include "objectives/continuous/n-d/RastriginFunction.hpp"
#include <math.h>

// Rastrigin is only defined over -5.12 <= x <= 5.12
RastriginFunction::RastriginFunction(
	unsigned int genomeLength
) : ContinuousObjective(genomeLength, -5.12, 5.12) {}

float RastriginFunction::checkFitness(Genome* genome) {
	float total = 0;
	for (unsigned int i = 0; i < this->genomeLength; i++) {
		double value = genome->getIndex<double>(i);
		total += pow(value, 2) - 10*cos(2*M_PI*value);
	}

	return -(10*this->genomeLength + total);
}
