#include "objectives/continuous/n-d/F8F2Function.hpp"
#include <math.h>

F8F2Function::F8F2Function(
	unsigned int genomeLength
) : ContinuousObjective(genomeLength, -2.048, 2.047) {}

double F8F2Function::F2(double x, double y) {
	return 100 * pow(pow(x, 2) - y, 2) + pow(1 - x, 2);
}

double F8F2Function::F8(double x) {
	return 1 + pow(x, 2)/4000 - cos(x);
}

float F8F2Function::checkFitness(Genome* genome) {
	float total = 0;
	for (unsigned int i = 0; i < this->genomeLength - 1; i++)
		total += this->F8(this->F2(
			genome->getIndex<double>(i),
			genome->getIndex<double>(i + 1)
		));
	return -(total + this->F8(this->F2(
		genome->getIndex<double>(this->genomeLength - 1),
		genome->getIndex<double>(1)
	)));
}
