#include "objectives/continuous/2d/BealesFunction.hpp"
#include <math.h>

// Beale's is only defined over -4.5 <= x, y <= 4.5
BealesFunction::BealesFunction() : ContinuousObjective(2, -4.5, 4.5) {}

float BealesFunction::checkFitness(Genome* genome) {
	double x = genome->getIndex<double>(0);
	double y = genome->getIndex<double>(1);
	return -(
		pow(1.5 - x + x*y, 2) +
		pow(2.25 - x + x*pow(y, 2), 2) +
		pow(2.625 - x + x*pow(y, 3), 2)
	);
}
