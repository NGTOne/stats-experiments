#include "objectives/discrete/binary/AverageFragmentFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		150,
		new AverageFragmentFunction(32),
		new GA(
			5,
			new TournamentSelection(2),
			new UniformCrossover(1, {0.3, 0.7}),
			new UniformMutation(0.05)
		),
		argv[1],
		std::stoul(argv[2]),
		32,
		1
	);

	exper.run();
}
