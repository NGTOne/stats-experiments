#include "objectives/continuous/2d/BukinNo6Function.hpp"
#include <math.h>

// Bukin No. 6 is only defined over -10 <= x, y <= 10
BukinNo6Function::BukinNo6Function() : ContinuousObjective(2) {}

float BukinNo6Function::checkFitness(Genome* genome) {
	double x = genome->getIndex<double>(0);
	double y = genome->getIndex<double>(1);
	return -(
		100*sqrt(std::abs(y - 0.01*pow(x, 2))) +
		0.01*std::abs(x + 10)
	);
}

std::vector<Locus*> BukinNo6Function::getLoci() {
	return {
		new NumericSetLocus<double>(-15, -5),
		new NumericSetLocus<double>(-3, 3)
	};
}
