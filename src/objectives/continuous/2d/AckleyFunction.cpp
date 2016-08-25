#include "objectives/continuous/2d/AckleyFunction.hpp"
#include <math.h>

// Ackley is only defined over -5 <= x, y <= 5
AckleyFunction::AckleyFunction() : ContinuousObjective(2, -5, 5) {}

float AckleyFunction::checkFitness(Genome* genome) {
	double x = genome->getIndex<double>(0);
	double y = genome->getIndex<double>(1);
	return -(
		-20 *
		exp(-0.2 * sqrt(0.5 * (pow(x, 2) + pow(y, 2)))) -
		exp(0.5 * (cos(2 * M_PI * x) + cos(2 * M_PI * y)))
		+ exp(1)
		+ 20
	);
}
