#include "objectives/continuous/n-d/GriewankFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		150,
		new GriewankFunction(32, -1000, 1000),
		new VEDA_GA(
			5,
			new TournamentSelection(2),
			new BlendedCrossover()
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		30
	);

	exper.run();
}
