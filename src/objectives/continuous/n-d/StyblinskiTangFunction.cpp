#include "objectives/continuous/n-d/StyblinskiTangFunction.hpp"
#include <math.h>

// Styblinski-Tang is only defined over -5 <= x <= 5
StyblinskiTangFunction::StyblinskiTangFunction(
	unsigned int genomeLength
) : ContinuousObjective(genomeLength, -5, 5) {}

float StyblinskiTangFunction::checkFitness(Genome* genome) {
	float total = 0;
	for (unsigned int i = 0; i < this->genomeLength; i++) {
		double x = genome->getIndex<double>(i);
		total += pow(x, 4) - 16*pow(x, 2) + 5*x;
	}

	return -(total/2);
}
