#include "objectives/continuous/n-d/F8F2Function.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		150,
		new F8F2Function(32),
		new VEDA_GA(
			5,
			new TournamentSelection(2),
			new UniformCrossover(1)
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		40
	);

	exper.run();
}
