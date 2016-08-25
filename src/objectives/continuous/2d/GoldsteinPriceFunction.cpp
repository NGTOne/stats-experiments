#include "objectives/continuous/2d/GoldsteinPriceFunction.hpp"
#include <math.h>

// Goldstein-Price is only defined over -2 <= x, y <= 2
GoldsteinPriceFunction::GoldsteinPriceFunction()
	: ContinuousObjective(2, -2, 2) {}

float GoldsteinPriceFunction::checkFitness(Genome* genome) {
	double x = genome->getIndex<double>(0);
	double y = genome->getIndex<double>(1);
	return -((
		1 + pow(x + y + 1, 2) *
		(19 - 14*x + 3*pow(x, 2) - 14*y + 6*x*y + 3*pow(y, 2))
	) * (
		30 + pow(2*x - 3*y, 2) *
		(18 - 32*x + 12*pow(x, 2) + 48*y - 36*x*y + 27*pow(y, 2))
	));
}
