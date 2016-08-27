#include "objectives/discrete/binary/AverageFragmentFunction.hpp"
#include "StatsExperiment.hpp"
#include <libHierGA/HierGA.hpp>
#include <string>

int main(int argc, char* argv[]) {
	StatsExperiment exper(
		50,
		new AverageFragmentFunction(32),
		new MuPlusLambdaES(
			new UniformCrossover(1),
			new UniformMutation(0.05),
			150
		),
		argv[1],
		std::stoul(argv[2]),
		32,
		1
	);

	exper.run();
}
