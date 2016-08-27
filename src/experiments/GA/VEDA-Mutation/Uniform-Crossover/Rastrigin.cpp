#include "objectives/continuous/n-d/RastriginFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		150,
		new RastriginFunction(32),
		new VEDA_GA(
			5,
			new TournamentSelection(2),
			new UniformCrossover(1, {0.3, 0.7})
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		260
	);

	exper.run();
}
