#include "objectives/continuous/2d/LeviNo13Function.hpp"
#include <math.h>

// Levi Function No. 13 is only defined over -10 <= x, y <= 10
LeviNo13Function::LeviNo13Function() : ContinuousObjective(2, -10, 10) {}

float LeviNo13Function::checkFitness(Genome* genome) {
	double x = genome->getIndex<double>(0);
	double y = genome->getIndex<double>(1);
	return -(
		pow(sin(3*M_PI*x), 2) +
		pow(x - 1, 2) * (1 + pow(sin(3*M_PI*y), 2)) +
		pow(y - 1, 2) * (1 + pow(sin(2*M_PI*y), 2))
	);
}
