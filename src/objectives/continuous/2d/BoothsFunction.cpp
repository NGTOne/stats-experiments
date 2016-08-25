#include "objectives/continuous/2d/BoothsFunction.hpp"
#include <math.h>

// Booth's is only defined over -10 <= x, y <= 10
BoothsFunction::BoothsFunction() : ContinuousObjective(2, -10, 10) {}

float BoothsFunction::checkFitness(Genome* genome) {
	double x = genome->getIndex<double>(0);
	double y = genome->getIndex<double>(1);
	return -(pow(x + 2*y - 7, 2) + pow(2*x + y - 5, 2));
}
