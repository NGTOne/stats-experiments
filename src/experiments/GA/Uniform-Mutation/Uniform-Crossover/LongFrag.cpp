#include "objectives/discrete/binary/LongestFragmentFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		150,
		new LongestFragmentFunction(32),
		new GA(
			5,
			new TournamentSelection(2),
			new UniformCrossover(1),
			new UniformMutation(0.05)
		),
		argv[1],
		std::stoul(argv[2]),
		32,
		0
	);

	exper.run();
}
