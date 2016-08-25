#include "objectives/continuous/2d/ThreeHumpCamelFunction.hpp"
#include <math.h>

// The three-hump camel function is only defined over -5 <= x, y <= 5
ThreeHumpCamelFunction::ThreeHumpCamelFunction()
	: ContinuousObjective(2, -5, 5) {}

float ThreeHumpCamelFunction::checkFitness(Genome* genome) {
	double x = genome->getIndex<double>(0);
	double y = genome->getIndex<double>(1);
	return -(2*pow(x, 2) - 1.05*pow(x, 4) + pow(x, 6)/6 + x*y + pow(y, 2));
}
