#include "objectives/continuous/2d/EasomFunction.hpp"
#include <math.h>

// Easom is only defined over -100 <= x, y <= 100
EasomFunction::EasomFunction() : ContinuousObjective(2, -100, 100) {}

float EasomFunction::checkFitness(Genome* genome) {
	double x = genome->getIndex<double>(0);
	double y = genome->getIndex<double>(1);
	return -((-cos(x))*cos(y)*exp(-(pow(x - M_PI, 2) + pow(y - M_PI, 2))));
}
