#include "objectives/continuous/n-d/RosenbrockFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		150,
		new RosenbrockFunction(32, -10, 10),
		new GA(
			5,
			new TournamentSelection(2),
			new UniformCrossover(1, {0.3, 0.7}),
			new SelfAdaptiveMutation(false)
		),
		argv[1],
		std::stoul(argv[2]),
		0,
		2000
	);

	exper.run();
}
