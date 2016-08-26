#include "objectives/continuous/n-d/SphereFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		50,
		new SphereFunction(32, -1000, 1000),
		new VEDA_GA(
			5,
			new TournamentSelection(2),
			new BlendedCrossover({0.3, 0.7})
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		1000
	);

	exper.run();
}
