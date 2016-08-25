#include "objectives/continuous/2d/MatyasFunction.hpp"
#include <math.h>

// Matyas is only defined over -10 <= x, y <= 10
MatyasFunction::MatyasFunction() : ContinuousObjective(2, -10, 10) {}

float MatyasFunction::checkFitness(Genome* genome) {
	double x = genome->getIndex<double>(0);
	double y = genome->getIndex<double>(1);
	return -(0.26*(pow(x, 2) + pow(y, 2)) - 0.48*x*y);
}
